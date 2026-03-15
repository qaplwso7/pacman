#pragma once

#include "../IPreparable.h"
#include "Room.h"

class IEntity;

class IRoomSide : public IPreparable {
public:
    virtual ~IRoomSide() = default;

    virtual void enter(IEntity* entity) = 0;
    void draw_into(const sf::RenderWindow & window);
};
