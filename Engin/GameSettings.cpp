#include "GameSettings.h"
#include "DxLib.h"
#include <string>
#include <array>

GameSettings& GameSettings::instance() {
    static GameSettings instance;
    return instance;
}

GameSettings::GameSettings()
    : m_windowMode(true)  // デフォルトはウィンドウモード
{
    load();
}

std::string toAbsolutePath(const std::string& relativePath) {
    std::array<char, _MAX_PATH> fullPath;
    if (_fullpath(fullPath.data(), relativePath.c_str(), _MAX_PATH) != nullptr) {
        return std::string(fullPath.data());
    }
    return relativePath; // 失敗したらそのまま返す
}

void GameSettings::load() {
    // Windows の INI API は相対パスを正しく扱えない場合があるため、絶対パスに変換する
    std::string absPath = toAbsolutePath("config.ini");

    char buffer[256] = {0};
    GetPrivateProfileStringA(
          "Title" // セクション名
        , "Title" // キー名
        , ""      // デフォルト
        , buffer
        , sizeof(buffer)
        , absPath.c_str()
    );
    m_title = buffer;


    // ウィンドウモードの設定を読み込む
    int windowMode = GetPrivateProfileIntA(
          "Display"             // セクション名
        , "WindowMode"          // キー名
        , m_windowMode ? 1 : 0  // デフォルト値
        , absPath.c_str()
    );
    m_windowMode = (windowMode != 0);

    // ウィンドウの横幅（ピクセル）
    m_width = GetPrivateProfileIntA(
          "Display"
        , "Width"
        , 640  // デフォルト値
        , absPath.c_str()
    );

    // ウィンドウの高さ（ピクセル）
    m_height = GetPrivateProfileIntA(
          "Display"
        , "Height"
        , 480  // デフォルト値
        , absPath.c_str()
    );

    // カラービット数（通常は 32bit 推奨）
    m_colorBit = GetPrivateProfileIntA(
          "Display"
        , "ColorBit"
        , 32  // デフォルト値
        , absPath.c_str()
    );
}
