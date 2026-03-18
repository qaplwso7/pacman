#pragma once

#include "../ChangeStateCommand.h"
#include "../../Application/core/IStateManager.h"
#include "../../Application/States/ExitState.h"

#include <memory>

class ExitCommand : public ChangeStateCommand {
public:
    ExitCommand(IStateManager& state_manager) : ChangeStateCommand(state_manager) {};
    void execute() override {
        m_state_manager.set_next_state(std::make_unique<ExitState>(m_state_manager));
    }
};
