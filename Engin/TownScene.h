#pragma once
#include "GameScene.h"
#include "TownSceneData.h"
#include <string>
#include <vector>
#include <unordered_map>

struct Icon {
    IconData data;  // アイコンの基本情報
    int normalHandle = -1;    // 通常状態の画像ハンドル
    int selectedHandle = -1;  // 選択状態の画像ハンドル
    bool isSelected = false;  // 選択状態
};

class TownScene : public GameScene {
private:
    int m_backgroundHandle = -1;
    std::vector<Icon> m_icons;
    std::vector<std::string> m_keyboardOrder;
    int m_selectedIndex = 0;
    std::unordered_map<std::string, int> m_keyboardIndexMap;

    bool m_keyboardEnabled;
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
