#pragma once

#include "CommonBuilder.h"

class SimpleBuilder : public CommonBuilder {
public:
    void create_rooms() override;
    void set_rooms_sides() override;
};
