#pragma once

#include "../core/IState.h"
#include <iostream>

class ExitState : public IState {
public:
    ExitState(IStateManager& state_manager) : IState(state_manager) {}

    bool do_step() override {
        return false;
    }
};
