#pragma once

#include "../core/IState.h"
#include <iostream>

class IStateManager;

class ExitState : public IState {
public:
    ExitState(IStateManager& state_manager) : m_state_manager(state_manager) {}
    bool do_step() override {
        std::cout << "Exit App" << std::endl;
        return false;
    }
};
