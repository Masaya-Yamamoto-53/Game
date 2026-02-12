#pragma once
#include "GameScene.h"

class TitleScene : public GameScene {
public:
    TitleScene(SceneManager* sceneManager);
    void update() override;
    void render() override;
};

