#pragma once

#include "../IPreparable.h"

class Room;
class IEntity;

class IRoomSide : public IPreparable {
public:
    virtual ~IRoomSide() = default;
    virtual void enter(IEntity* entity) = 0;
};
