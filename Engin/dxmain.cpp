#include "DxLib.h"
#include "GameSettings.h"

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

    // Load game settings
    auto& settings = GameSettings::instance();

    // Initialize the Dx Library
    if (initializeDxLib(settings) == false) {
        return -1;
    }

    // Main loop
    while (true) {
        // DxLibが終了要求を返したらループを抜ける
        if (ProcessMessage() != 0) {
            break;
        }
    }

    // Finalize the DX Library
    DxLib_End();

    return 0;
}
