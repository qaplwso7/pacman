#pragma once

#include "IEntity.h"
#include "IVisitable.h"

class IStaticEntity : public IEntity, public IVisitable {
public:
    virtual std::unique_ptr<IStaticEntity> clone() const = 0;
    virtual ~IStaticEntity() = default;
};


