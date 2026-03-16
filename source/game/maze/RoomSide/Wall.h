#pragma once

#include "../IRoomSide.h"

class Room;

class Wall : public IRoomSide {
public:
    explicit Wall(std::shared_ptr<Room> room);

    void enter(IEntity* entity) override;
    void draw_into(sf::RenderWindow &window) override { window.draw(m_line, 2, sf::PrimitiveType::Lines); };
    void prepare_for_drawing() override;

private:
    std::weak_ptr<Room> m_room;
    sf::Vertex m_line[2];
};