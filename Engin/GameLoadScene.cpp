#include "GameLoadScene.h"
#include "SceneManager.h"
#include "DxLib.h"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

GameLoadScene::GameLoadScene(SceneManager* sceneManager)
    : GameScene(sceneManager)
{
}

void GameLoadScene::update() {
    if (!m_loaded) {
        load("save\\save.json");

        // Ÿ‚ÌƒV[ƒ“‚Ö‘JˆÚ
        if (m_locationType == "town") {
            m_sceneManager->changeScene(SceneType::Town, m_loadFile);
        }
        m_loaded = true;
    }
}

void GameLoadScene::render() {
    DrawBox(
          0
        , 0
        , m_windowWidth
        , m_windowHeight
        , GetColor(255, 0, 0)
        , TRUE
    );
}

void GameLoadScene::load(const std::string& filename) {
    std::ifstream ifs(filename);
    json save;
    ifs >> save;

    // Œ»İ’n‚ğæ“¾
    std::string type = save["location"]["type"];
    std::string name = save["location"]["name"];
    printf("Loaded location: %s\n", name.c_str());

    m_locationType = type;
    m_loadFile = "assets\\" + name + ".json";
    printf("Transitioning to scene with file: %s\n", m_loadFile.c_str());
}
