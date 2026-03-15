#pragma once

#include "Room.h"
#include "IRoomSide.h"
#include <memory>
#include <vector>

class Maze : public IDrawable {
public:
    Maze(std::vector<std::unique_ptr<Room>>&& rooms) : m_rooms(std::move(rooms)) {};
    void draw_into(sf::RenderWindow &window) override;
    ~Maze() = default;
private:
    std::vector<std::unique_ptr<Room>> m_rooms;
};
