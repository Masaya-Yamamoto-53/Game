#pragma once
#include <string>

class GameSettings {
private:
    std::string m_title;
    bool m_windowMode;
    int m_width;
    int m_height;
    int m_colorBit;
public:
    static GameSettings& instance();

    // ウィンドウタイトルを取得
    std::string getTitle() const { return m_title; }
    // ウィンドウモードを取得
    bool isWindowMode() const { return m_windowMode; }
    // 画面設定の各種情報を取得
    int getWidth()    const { return m_width;    }
    int getHeight()   const { return m_height;   }
    int getColorBit() const { return m_colorBit; }
private:
    // Constructor
    GameSettings();
    // Load settings from INI file
    void load();
};

