#pragma once

#include "../IRoomSide.h"

class Room;

class Wall : public IRoomSide {
public:
    explicit Wall(Room &room) : m_room(room) {}

    void enter(IEntity* entity) override {};
    void draw_into(sf::RenderWindow &window) override { window.draw(m_line, 2, sf::PrimitiveType::Lines); };
    void prepare_for_drawing() override;

private:
    Room& m_room;
    sf::Vertex m_line[2];
};