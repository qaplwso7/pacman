#pragma once

#include "../user_interface/core/IDrawable.h"

class IPreparable : public IDrawable {
public:
    virtual ~IPreparable() = default;
    void virtual prepare_for_drawing() = 0;
};

