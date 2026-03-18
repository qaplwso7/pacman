#pragma once

#include "../IRoomSide.h"
#include "../../Entities/IEntity.h"

class IEntity;
class Room;

class Pass : public IRoomSide {
public:
    Pass(std::shared_ptr<Room> room1, std::shared_ptr<Room> room2)
    : m_room1(room1), m_room2(room2) {}

    void enter(IEntity* entity) override {
        if(entity->get_location() == m_room1.lock().get())
            entity->set_location(m_room2.lock().get());
        else if(entity->get_location() == m_room2.lock().get())
            entity->set_location(m_room1.lock().get());
    }
    void prepare_for_drawing() override {}
    void draw_into(sf::RenderWindow& window) override {}
private:
    std::weak_ptr<Room> m_room1;
    std::weak_ptr<Room> m_room2;
};
