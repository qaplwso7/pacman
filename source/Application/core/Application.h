#pragma once

#include <memory>
#include <iostream>

#include "IState.h"
#include "IStateManager.h"
#include "../States/SelectState.h"

class Application : public IStateManager {
public:
    Application() { m_ptr_state_current =
        std::make_unique<SelectState>(*this, config::SELECT_LEVEL_VIDEO_MODE, config::SELECT_LEVEL_TITLE); }
    void set_initial_state(std::unique_ptr<IState> state) {
        m_ptr_state_current = std::move(state); }

    int run();

    void set_next_state(std::unique_ptr<IState>&& ptr_state) override {
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

