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
// character-module constructors). Before loading a character module, unload
// whichever character module is currently resident so the shared slot frees up
// and the new XexLoadImage succeeds at 0x88000000.
//
// Note: this only works when UnloadUserModule can find the recompiled module.
// Module lookup normalizes the kernel's NT device path, which is why
// NormalizeGuestPath must strip \Device\Harddisk0\Partition1 (see the SDK fork
// commit "strip NT device prefix in NormalizeGuestPath").

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

bool IsCharacterModule(std::string_view name) {
  for (const char* m : kCharacterModules) {
    if (rex::string::utf8_equal_case(name, m)) {
      return true;
    }
  }
  return false;
}

}  // namespace

REX_HOOK_RAW(sub_82088E10) {
  const uint32_t path_addr = ctx.r3.u32;

  if (path_addr != 0) {
    const char* path = rex::memory::GuestPtr<const char*>(base, path_addr);
    const std::string requested = rex::string::utf8_find_name_from_guest_path(path);

    if (IsCharacterModule(requested)) {
      // Probe with the requested path's directory (e.g. game:\media\Module\)
      // rather than a bare filename: a name with no device makes ResolvePath
      // log a spurious warning for every candidate that is not loaded.
      std::string directory(path);
      const auto sep = directory.find_last_of("\\/");
      directory.resize(sep == std::string::npos ? 0 : sep + 1);

      for (const char* m : kCharacterModules) {
        auto module = REX_KERNEL_STATE()->GetModule(directory + m, /*user_only=*/true);
        if (!module) {
          continue;
        }
        REXSYS_INFO(
            "futari fix: unloading resident character module '{}' before loading '{}'",
            module->name(), requested);
        ctx.r3.u64 = module->hmodule_ptr();
        __imp__XexUnloadImage(ctx, base);
      }
    }
  }

  ctx.r3.u32 = path_addr;
  __imp__sub_82088E10(ctx, base);
}
