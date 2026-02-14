#pragma once
#include "GameScene.h"
#include "SceneType.h"
#include <string>
#include <memory>

class SceneManager {
private:
    SceneType m_currentSceneType;
    std::unique_ptr<GameScene> m_currentScene;
public:
    SceneManager();
    void changeScene(
          SceneType newSceneType
        , const std::string fileName = ""
    );
    void update();
    void render();
private:
    std::unique_ptr<GameScene> createScene(SceneType sceneType);
};

