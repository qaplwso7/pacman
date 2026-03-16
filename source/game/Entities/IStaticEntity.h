#pragma once

#include "IEntity.h"

class IStaticEntity : public IEntity {
public:
    virtual std::unique_ptr<IStaticEntity> clone() const = 0;
    virtual ~IStaticEntity() = default;
};


