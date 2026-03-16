#pragma once

#include <memory>

class Maze;
class GameContext;

class IGameBuilder {
public:
    virtual ~IGameBuilder() = default;
    virtual void create_rooms() = 0;
    virtual void set_rooms_sides() = 0;
    virtual void create_context(float dynamic_objects_ratio) = 0;
    virtual std::unique_ptr<Maze> get_maze() = 0;
    virtual std::unique_ptr<GameContext> get_context() = 0;
};