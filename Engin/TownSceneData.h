#pragma once
#include <string>
#include <vector>

struct IconData {
    std::string id;
    std::string type;
    std::string name;

    std::string normalImage;
    std::string selectedImage;

    int x, y;
    int width, height;

    std::string hotkey;
    std::string destinationScene;
};

struct TownSceneData {
    std::string id;
    std::string name;
    std::string backgroundImage;

    bool keyboardEnabled = true;
    bool mouseEnabled = true;

    std::vector<std::string> keyboardOrder;
    std::vector<IconData> icons;
};
