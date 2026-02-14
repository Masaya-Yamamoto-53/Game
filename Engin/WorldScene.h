#pragma once
#include "GameScene.h"

class WorldScene : public GameScene {
public:
    WorldScene(SceneManager* sceneManager);
    void update() override;
    void render() override;
};

