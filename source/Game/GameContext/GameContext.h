#pragma once

#include <vector>
#include <memory>

#include "../Entities/IDynamicEntity.h"
#include "../Entities/IStaticEntity.h"
#include "../Entities/Pacman.h"

class GameContext {
public:
    enum State{ INGAME, WIN, LOST } state = INGAME;

    std::unique_ptr<GameContext> clone() const;

    Pacman pacman;
    std::vector<std::unique_ptr<IDynamicEntity>> dynamic_objects;
    std::vector<std::unique_ptr<IStaticEntity>> static_objects;
};

