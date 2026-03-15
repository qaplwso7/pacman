#pragma once

#include "../IRoomSide.h"
#include "../../entities/IEntity.h"

class IEntity;
class Room;

class Pass : public IRoomSide {
public:
    Pass(std::shared_ptr<Room> room1, std::shared_ptr<Room> room2) : m_room1(std::move(room1)), m_room2(std::move(room2)) {}
    void enter(IEntity& entity) override {
        if(entity.get_location() == m_room1)
            entity.set_location(m_room2);
        else if(entity.get_location() == m_room2)
            entity.set_location(m_room1);
    }
    void prepare_for_drawing() override {}
    void draw_into(sf::RenderWindow& window) override {}
private:
    std::shared_ptr<Room> m_room1;
    std::shared_ptr<Room> m_room2;
};
