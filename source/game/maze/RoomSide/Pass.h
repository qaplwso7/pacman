#pragma once

#include "../IRoomSide.h"
#include "../../Entities/IEntity.h"

class IEntity;
class Room;

class Pass : public IRoomSide {
public:
    Pass(Room& room1, Room& room2) : m_room1(room1), m_room2(room2) {}
    void enter(IEntity* entity) override {
        if(entity->get_location() == &m_room1)
            entity->set_location(&m_room2);
        else if(entity->get_location() == &m_room2)
            entity->set_location(&m_room1);
    }
    void prepare_for_drawing() override {}
    void draw_into(sf::RenderWindow& window) override {}
private:
    Room& m_room1;
    Room& m_room2;
};
