#include "SceneManager.h"
#include "DxLib.h"
#include <memory>

SceneManager::SceneManager()
{
    m_currentScene = createScene(m_currentSceneType);
    m_currentSceneType = SceneType::Logo;
}

void SceneManager::changeScene(
      SceneType newSceneType
    , const std::string fileName
) {
    printf("Changing scene to %d\n", static_cast<int>(newSceneType));
    m_currentScene = createScene(newSceneType);
    m_currentSceneType = newSceneType;

    if (!fileName.empty()) {
        printf("Loading world scene from file: %s\n", fileName.c_str());
        m_currentScene->load(fileName);
    }
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
    case SceneType::GameLoad:
        return std::make_unique<GameLoadScene>(this);
    case SceneType::Town:
        return std::make_unique<TownScene>(this);
    default:
        return nullptr;
    }
}
