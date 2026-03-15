#pragma once

#include "../maze/IRoomSide.h"
#include "IEntity.h"

class Pacman : public IEntity {
public:
    Pacman();
    void draw_into(sf::RenderWindow &window) override;
    void prepare_for_drawing() override;
    void move(Room::Direction direction);

private:
    sf::CircleShape m_circle;
};