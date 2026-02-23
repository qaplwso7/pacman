#pragma once

#include "../ChangeStateCommand.h"
#include "../../application/core/IStateManager.h"
#include "../../application/states/ExitState.h"

#include <memory>

class ExitCommand : public ChangeStateCommand {
public:
    ExitCommand(IStateManager& state_manager) : ChangeStateCommand(state_manager) {};
    void execute() override {
        m_state_manager.set_next_state(std::make_unique<ExitState>(m_state_manager));
    }
};
