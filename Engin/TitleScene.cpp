#include "TitleScene.h"
#include "SceneManager.h"
#include "InputDeviceHub.h"
#include "DxLib.h"

TitleScene::TitleScene(SceneManager* sceneManager)
    : GameScene(sceneManager)
{
}

void TitleScene::update() {
    if (InputDeviceHub::instance().isKeyTriggered(KEY_INPUT_RETURN)
     || InputDeviceHub::instance().isMousePressed(MOUSE_INPUT_LEFT)) {
         m_sceneManager->changeScene(SceneType::GameLoad);
    }
}

void TitleScene::render() {
    DrawBox(
          0
        , 0
        , m_windowWidth
        , m_windowHeight
        , GetColor(0, 0, 0)
        , TRUE
    );
}
