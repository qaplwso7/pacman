#pragma once

#include "../IPreparable.h"
#include "../maze/Room.h"

class IEntity : public IPreparable {
public:
    void set_location(Room* ptr_room) {
        m_ptr_room = ptr_room;
        prepare_for_drawing();
    }
    Room* get_location() const { return m_ptr_room; }

protected:
    Room* m_ptr_room = nullptr;
};

