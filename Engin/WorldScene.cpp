#include "WorldScene.h"
#include "SceneManager.h"
#include "InputDeviceHub.h"
#include "DxLib.h"

WorldScene::WorldScene(SceneManager* sceneManager)
    : GameScene(sceneManager)
{
}

void WorldScene::update() {
}

void WorldScene::render() {
    DrawBox(
          0
        , 0
        , m_windowWidth
        , m_windowHeight
        , GetColor(255, 255, 255)
        , TRUE
    );
}
