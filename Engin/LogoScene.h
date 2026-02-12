#pragma once
#include "GameScene.h"

class LogoScene : public GameScene {
private:
    int m_startTime;
public:
    LogoScene(SceneManager* sceneManager);
    void update() override;
    void render() override;
};
