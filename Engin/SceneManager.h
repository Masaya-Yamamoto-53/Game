#pragma once
#include <memory>
#include "GameScene.h"
#include "SceneType.h"

class SceneManager {
private:
    SceneType m_currentSceneType;
    std::unique_ptr<GameScene> m_currentScene;
public:
    SceneManager();
    void changeScene(SceneType newSceneType);
    void update();
    void render();
private:
    std::unique_ptr<GameScene> createScene(SceneType sceneType);
};

