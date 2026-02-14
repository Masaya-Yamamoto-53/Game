#include "TownSceneLoader.h"
#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

TownSceneData TownSceneLoader::load(const std::string& filename)
{
    TownSceneData data;

    std::ifstream ifs(filename);
    json j = json::parse(ifs);

    // 町のID
    data.id = j["town"]["id"];
    // 町の名前
    data.name = j["town"]["name"];
    // 背景
    data.backgroundImage = j["town"]["backgroundImage"];

    // ナビゲーション
    data.keyboardEnabled = j["navigation"]["keyboardSelection"]["enabled"];
    if (data.keyboardEnabled) {
        for (auto& id : j["navigation"]["keyboardSelection"]["order"]) {
            data.keyboardOrder.push_back(id);
        }
    }

    data.mouseEnabled = j["navigation"]["mouseSelection"]["enabled"];

    // アイコン
    for (auto& item : j["icons"]) {
        IconData icon;

        icon.id = item["id"];
        icon.type = item["type"];
        icon.name = item["name"];

        icon.normalImage = item["image"]["normal"];
        icon.selectedImage = item["image"]["selected"];

        icon.x = item["position"]["x"];
        icon.y = item["position"]["y"];
        icon.width = item["size"]["width"];
        icon.height = item["size"]["height"];

        icon.hotkey = item["hotkey"];
        icon.destinationScene = item["destinationScene"];

        data.icons.push_back(icon);
    }

    return data;
}
