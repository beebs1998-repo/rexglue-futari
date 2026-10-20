// futari - ReXGlue Recompiled Project
//
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <rex/rex_app.h>
#include <rex/ui/keybinds.h>

class FutariApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<FutariApp>(new FutariApp(ctx, "futari",
        PPCImageConfig));
  }

  void OnPostSetup() override {
    // F11 toggles the fullscreen cvar; ReXApp's change callback on
    // "fullscreen" applies it to the window. The value is persisted to
    // futari.toml by the save-on-exit paths (OnWindowCloseRequested /
    // OnShutdown, see OnConfigurePaths for the path capture).
    rex::ui::RegisterBind("bind_fullscreen", "F11", "Toggle fullscreen", [] {
      rex::cvar::SetFlagByName("fullscreen",
                               REXCVAR_GET(fullscreen) ? "false" : "true");
    });
  }

  void OnConfigurePaths(rex::PathConfig& paths) override {
    // Capture the config file path so the cvar state can be saved on exit
    // (the SDK only persists cvars via the F4 "Save to config" button).
    config_path_ = paths.config_path;
  }

  bool OnWindowCloseRequested() override {
    // The close path ends in ReXApp::OnClosing hard-exiting the process
    // (std::_Exit after TerminateTitle) without running OnDestroy /
    // OnShutdown, so save the cvar state here - the last app-side hook
    // before that exit (Alt-F4, X button).
    if (!config_path_.empty()) {
      rex::cvar::SaveConfig(config_path_);
    }
    return true;
  }

  void OnShutdown() override {
    rex::ui::UnregisterBind("bind_fullscreen");
    if (!config_path_.empty()) {
      rex::cvar::SaveConfig(config_path_);
    }
  }

  // Override virtual hooks for customization:
  // void OnPostInitLogging() override {}
  // void OnPreSetup(rex::RuntimeConfig& config) override {}
  // void OnLoadXexImage(std::string& xex_image) override {}
  // void OnPostLoadXexImage() override {}
  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
  // std::unique_ptr<rex::ui::ImGuiDialog> CreateAchievementsOverlay() override;
  // std::unique_ptr<rex::ui::AchievementNotificationDialog>
  // CreateAchievementNotificationDialog() override;

 private:
  std::filesystem::path config_path_;
};
