#pragma once

#include "../Maze/IRoomSide.h"
#include "IEntity.h"
#include "IVisitable.h"

class IDynamicEntity : public IEntity, public IVisitable {
public:
    virtual std::unique_ptr<IDynamicEntity> clone() const = 0;
    virtual void action() = 0; /// call each frame
    virtual ~IDynamicEntity() = default;
};