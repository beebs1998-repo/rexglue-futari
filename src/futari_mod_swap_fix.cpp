// futari - Character module swap fix
//
// The 8 character modules (palm/hirow/kiniro/reco x normal/abnormal) all share
// the same image slot (base 0x88000000, fixed by their XEX headers). The
// original game relies on the Xbox kernel loader placing a newly loaded module
// at a free base while the previously loaded one stays resident. Recompiled
// modules are pinned to their baked addresses, so the second XexLoadImage
// fails with a base overlap (AllocFixed reserve-on-reserve). The module
// constructor then stores handle 0 at offset 248 / entry 0 at offset 252, and
// the game later calls the entry, crashing at guest address 0x0.
//
// Fix: intercept sub_82088E10 (the XexLoadImage wrapper used only by the 8
// character-module constructors). Before loading a character module, unload the
// currently-loaded character module so the shared slot frees up and the new
// XexLoadImage succeeds at 0x88000000.

#include <rex/hook.h>
#include <rex/string/utf8.h>
#include <rex/system/xmodule.h>

REX_EXTERN(__imp__sub_82088E10);
REX_EXTERN(__imp__XexUnloadImage);

namespace {

constexpr const char* kCharacterModules[] = {
    "palm_normal.xex",   "palm_abnormal.xex",
    "hirow_normal.xex",  "hirow_abnormal.xex",
    "kiniro_normal.xex", "kiniro_abnormal.xex",
    "reco_normal.xex",   "reco_abnormal.xex",
};

}  // namespace

REX_HOOK_RAW(sub_82088E10) {
  const uint32_t path_addr = ctx.r3.u32;

  if (path_addr != 0) {
    const char* path = rex::memory::GuestPtr<const char*>(base, path_addr);
    std::string name = rex::string::utf8_find_name_from_guest_path(path);

    bool is_character_module = false;
    for (const char* m : kCharacterModules) {
      if (rex::string::utf8_equal_case(name, m)) {
        is_character_module = true;
        break;
      }
    }

    REXSYS_INFO("futari fix diag: hook entry path='{}' name='{}' is_char={}",
                path, name, is_character_module ? 1 : 0);

    if (is_character_module) {
      for (const char* m : kCharacterModules) {
        auto module = REX_KERNEL_STATE()->GetModule(m, /*user_only=*/true);
        if (module) {
          REXSYS_INFO("futari fix diag: GetModule('{}') -> FOUND path='{}' name='{}'",
                      m, module->path(), module->name());
        }
        auto module_gp = REX_KERNEL_STATE()->GetModule(
            (std::string("media/module/") + m), /*user_only=*/true);
        auto module_GP = REX_KERNEL_STATE()->GetModule(
            (std::string("media/Module/") + m), /*user_only=*/true);
        REXSYS_INFO("futari fix diag: GetModule('{}') -> {} (bare), {} (media/module/), {} (media/Module/)",
                    m,
                    module ? static_cast<const void*>(&*module) : nullptr,
                    module_gp ? static_cast<const void*>(&*module_gp) : nullptr,
                    module_GP ? static_cast<const void*>(&*module_GP) : nullptr);
        if (!module && module_gp) {
          module = module_gp;
        }
        if (!module && module_GP) {
          module = module_GP;
        }
        if (!module) {
          continue;
        }
        REXSYS_INFO("futari fix: unloading previously loaded character module '{}' before loading '{}'",
                    m, name);
        ctx.r3.u64 = module->hmodule_ptr();
        __imp__XexUnloadImage(ctx, base);
      }
    }
  }

  ctx.r3.u32 = path_addr;
  __imp__sub_82088E10(ctx, base);
}
