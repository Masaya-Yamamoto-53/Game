#include "TownScene.h"
#include "TownSceneLoader.h"
#include "SceneManager.h"
#include "InputDeviceHub.h"
#include "DxLib.h"

TownScene::TownScene(SceneManager* sceneManager)
    : GameScene(sceneManager)
{
}

void TownScene::update() {
    // マウス選択
    if (m_mouseEnabled) {
        updateMouseSelection();
    }

    // キーボード選択
    if (m_keyboardEnabled) {
        if (InputDeviceHub::instance().isKeyTriggered(KEY_INPUT_W)
         || InputDeviceHub::instance().isKeyTriggered(KEY_INPUT_D)) {
            moveSelection(+1);
        }
        if (InputDeviceHub::instance().isKeyTriggered(KEY_INPUT_S)
         || InputDeviceHub::instance().isKeyTriggered(KEY_INPUT_A)) {
            moveSelection(-1);
        }
    }

    // 選択状態を更新
    for (auto& icon : m_icons) {
        icon.isSelected = icon.data.id == m_keyboardOrder[m_selectedIndex];
    }

    if (m_mouseEnabled && InputDeviceHub::instance().isMouseTriggered(MOUSE_INPUT_LEFT)
     || m_keyboardEnabled && InputDeviceHub::instance().isKeyTriggered(KEY_INPUT_RETURN)) {
        // 選択されたアイコンの処理を実行
        for (const auto& icon : m_icons) {
            if (icon.isSelected) {
                printf("Icon clicked: %s\n", icon.data.id.c_str());
                // ここにアイコン選択時の処理を追加
            }
        }
    }
}

void TownScene::render() {
    // 背景描画
    DrawGraph(0, 0, m_backgroundHandle, TRUE);

    // アイコン描画
    for (const auto& icon : m_icons) {
        int handle = icon.isSelected ? icon.selectedHandle : icon.normalHandle;
        DrawGraph(
              icon.data.x
            , icon.data.y
            , handle
            , TRUE
        );
    }
}

void TownScene::load(const std::string& filename) {
    // JSON 読み込み
    TownSceneData data = TownSceneLoader::load(filename);

    // 背景画像
    m_backgroundHandle = LoadGraph(data.backgroundImage.c_str());
    printf("Loaded background image: %s\n", data.backgroundImage.c_str());

    // アイコンの画像読み込み
    for (auto& iconData : data.icons) {
        Icon icon;

        icon.data = iconData;
        icon.normalHandle = LoadGraph(iconData.normalImage.c_str());
        icon.selectedHandle = LoadGraph(iconData.selectedImage.c_str());
        printf("Loaded icon: %s\n", iconData.id.c_str());
        m_icons.push_back(icon);
    }
    // ナビゲーション設定
    m_keyboardEnabled = data.keyboardEnabled;
    m_mouseEnabled    = data.mouseEnabled;
    m_keyboardOrder   = data.keyboardOrder;
    m_keyboardIndexMap.clear();
    for (int i = 0; i < (int)m_keyboardOrder.size(); ++i) {
        m_keyboardIndexMap[m_keyboardOrder[i]] = i;
    }
}

void TownScene::moveSelection(int dir) {
    if (m_keyboardOrder.empty()) return;

    m_selectedIndex += dir;

    if (m_selectedIndex < 0) {
        m_selectedIndex = (int)m_keyboardOrder.size() - 1;
    }
    if (m_selectedIndex >= (int)m_keyboardOrder.size()) {
        m_selectedIndex = 0;
    }
}

void TownScene::updateMouseSelection() {
    bool found = false;
    int mx = InputDeviceHub::instance().getMouseX();
    int my = InputDeviceHub::instance().getMouseY();

    int i = 0;
    for (auto& icon : m_icons) {
        bool inside =
            mx >= icon.data.x &&
            mx <= icon.data.x + icon.data.width &&
            my >= icon.data.y &&
            my <= icon.data.y + icon.data.height;

        if (inside) {
            auto it = m_keyboardIndexMap.find(icon.data.id);
            if (it != m_keyboardIndexMap.end()) {
                m_selectedIndex = it->second;
            }
            break;
        }
    }
}
