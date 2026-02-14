#pragma once
#include "TownSceneData.h"

class TownSceneLoader {
public:
    static TownSceneData load(const std::string& filename);
};

