#pragma once

#include "CommonBuilder.h"

class ComplexBuilder : public CommonBuilder {
public:
    void create_rooms() override;
    void set_rooms_sides() override;
};