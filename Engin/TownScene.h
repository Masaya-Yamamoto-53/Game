#pragma once
#include "GameScene.h"
#include "TownSceneData.h"
#include <string>
#include <vector>
#include <unordered_map>

// アイコンの描画と選択状態を管理する構造体
struct Icon {
    IconData data;            // アイコンの基本情報
    int normalHandle = -1;    // 通常状態の画像ハンドル
    int selectedHandle = -1;  // 選択状態の画像ハンドル
    bool isSelected = false;  // 選択状態
};

class TownScene : public GameScene {
private:
    // 背景画像のハンドル
    int m_backgroundHandle = -1;
    // アイコンのリスト
    std::vector<Icon> m_icons;
    // キーボード選択の順序とインデックスマップ
    std::vector<std::string> m_keyboardOrder;
    // 現在選択されているアイコンのインデックス
    int m_selectedIndex = 0;
    // アイコンIDからキーボード選択のインデックスへのマップ
    std::unordered_map<std::string, int> m_keyboardIndexMap;

    // キーボード選択が有効かどうか
    bool m_keyboardEnabled;
    // マウス選択が有効かどうか
    bool m_mouseEnabled;
public:
    TownScene(SceneManager* sceneManager);
    void update() override;
    void render() override;
    void load(const std::string& filename);
private:
    void moveSelection(int dir);
    void updateMouseSelection();
};
