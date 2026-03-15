#pragma once

#include <vector>
#include <memory>

#include "entities/IDynamicEntity.h"
#include "entities/IStaticEntity.h"
#include "entities/Pacman.h"

// /// оставим на доработку в 5 пункте
// class GameContext {
// public:
//     enum State{ INGAME, WIN, LOST } state = INGAME;
//     Pacman pacman;
//     std::vector<std::unique_ptr<IDynamicEntity>> dynamic_objects;
//     std::vector<std::unique_ptr<IStaticEntity>> static_objects;
//
//     /// нужно ли менять на значение?
//     /// с указателями вроде лучше, для 5 пункта
//     std::unique_ptr<GameContext> clone() const;
// };

