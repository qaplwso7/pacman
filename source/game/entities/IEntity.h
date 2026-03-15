#pragma once

#include "../IPreparable.h"
class Room;

class IEntity : IPreparable {
public:
    void set_location(std::shared_ptr<Room> ptr_room) {
        m_ptr_room = std::move(ptr_room);
        prepare_for_drawing();
    }
    std::shared_ptr<Room> get_location() const { return m_ptr_room; }

protected:
    std::shared_ptr<Room> m_ptr_room;
};

