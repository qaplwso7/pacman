#pragma once

#include <memory>
#include <iostream>

#include "IState.h"
#include "IStateManager.h"

class Application : public IStateManager {
public:
    int run();

private:
    void set_next_state(std::unique_ptr<IState> ptr_state) override {
        m_ptr_state_next = std::move(ptr_state);
    }
    void apply_deffer_state_change() {
        if(m_ptr_state_next)
            m_ptr_state_current = std::move(m_ptr_state_next);
    }

private:
    std::unique_ptr<IState> m_ptr_state_next;
    std::unique_ptr<IState> m_ptr_state_current;
};

