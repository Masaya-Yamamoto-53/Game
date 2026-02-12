#include "LogoScene.h"
#include "SceneManager.h"
#include "DxLib.h"

LogoScene::LogoScene(SceneManager* sceneManager)
    : GameScene(sceneManager)
{
    m_startTime = GetNowCount();
}

void LogoScene::update() {
    int now = GetNowCount();
    int elapsed = now - m_startTime;
    if (elapsed >= 2000) {
        m_sceneManager->changeScene(SceneType::Title);
    }
}

void LogoScene::render() {
    DrawBox(
          0
        , 0
        , m_windowWidth
        , m_windowHeight
        , GetColor(255, 255, 255)
        , TRUE
    );
}
