#pragma once

#include "../maze/IRoomSide.h"
#include "IEntity.h"

class IDynamicEntity : public IEntity {
public:
    virtual std::unique_ptr<IDynamicEntity> clone() const = 0;
    virtual void action() = 0; /// call each frame
    virtual ~IDynamicEntity() = default;
};