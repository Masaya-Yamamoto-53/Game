#include "DxLib.h"
#include "GameSettings.h"
#include "InputDeviceHub.h"
#include "SceneManager.h"

bool initializeDxLib(const GameSettings& settings) {
    // Dx Library Settings
    // Disable outputting log files
    SetOutApplicationLogValidFlag(FALSE);
    // Set the window title
    SetMainWindowText(settings.getTitle().c_str());
    // Change to window mode
    ChangeWindowMode(settings.isWindowMode());
    // Set screen mode (resolution and color depth)
    SetGraphMode(
          settings.getWidth()
        , settings.getHeight()
        , settings.getColorBit()
    );
    // Expand the window size by 1 times
    SetWindowSizeExtendRate(1.0);
    // Set vertical sync
    SetWaitVSyncFlag(FALSE);
    // Always run the application
    SetAlwaysRunFlag(TRUE);

    return DxLib_Init() != -1;
}

int WINAPI WinMain(
      _In_ HINSTANCE hInstance
    , _In_opt_ HINSTANCE hPrevInstance
    , _In_ LPSTR lpCmdLine
    , _In_ int nCmdShow
) {
    // Suppress unused parameter warnings
    (void)hInstance;
    (void)hPrevInstance;
    (void)lpCmdLine;
    (void)nCmdShow;

    // コンソールを作成
    AllocConsole();
    FILE* out = nullptr;
    freopen_s(&out, "CON", "w", stdout);

    // Load game settings
    auto& settings = GameSettings::instance();

    // Initialize the Dx Library
    if (initializeDxLib(settings) == false) {
        return -1;
    }

    // User code initialization
    SceneManager sceneManager;

    // Set the drawing target to the back screen
    SetDrawScreen(DX_SCREEN_BACK);

    // Main loop
    while (true) {
        // DxLibが終了要求を返したらループを抜ける
        if (ProcessMessage() != 0) {
            break;
        }
        // Clear the screen
        ClearDrawScreen();

        // Update input devices and the current scene
        InputDeviceHub::instance().update();
        // Update and render the current scene
        sceneManager.update();
        sceneManager.render();

        // Update the screen
        ScreenFlip();
    }

    // Finalize the DX Library
    DxLib_End();

    return 0;
}
