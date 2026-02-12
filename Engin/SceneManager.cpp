#include "SceneManager.h"
#include "DxLib.h"
#include <memory>

SceneManager::SceneManager()
{
    m_currentScene = createScene(m_currentSceneType);
    m_currentSceneType = SceneType::Logo;
}

void SceneManager::changeScene(SceneType newSceneType) {
    m_currentScene = createScene(newSceneType);
    m_currentSceneType = newSceneType;
}

void SceneManager::update() {
    m_currentScene->update();
}

void SceneManager::render() {
    m_currentScene->render();
}

std::unique_ptr<GameScene> SceneManager::createScene(SceneType sceneType) {
    switch (sceneType) {
    case SceneType::Logo:
        return std::make_unique<LogoScene>(this);
    case SceneType::Title:
        return std::make_unique<TitleScene>(this);
    default:
        return nullptr;
    }
}
