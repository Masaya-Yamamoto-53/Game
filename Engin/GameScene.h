#pragma once
#include "GameSettings.h"
#include <string>

class SceneManager;

class GameScene {
protected:
    SceneManager* m_sceneManager;
    int m_windowWidth;
    int m_windowHeight;
public:
    GameScene(SceneManager* sceneManager)
        : m_sceneManager(sceneManager)
        , m_windowWidth(GameSettings::instance().getWidth())
        , m_windowHeight(GameSettings::instance().getHeight()) {}

    virtual void update() = 0;
    virtual void render() = 0;
    virtual void load(const std::string& filename) {}
    virtual ~GameScene() = default;
};
