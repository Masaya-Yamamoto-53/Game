#pragma once
#include "GameScene.h"
#include "SceneType.h"
#include <string>

class GameLoadScene : public GameScene {
private:
    bool m_loaded = false;
    std::string m_locationType;
    std::string m_loadFile;
public:
    GameLoadScene(SceneManager* sceneManager);
    void update() override;
    void render() override;
    void load(const std::string& filename) override;
};

