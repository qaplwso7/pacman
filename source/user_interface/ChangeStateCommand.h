#pragma once

#include "../application/core/IStateManager.h"
#include "core/ISelectCommand.h"

class ChangeStateCommand : public ISelectCommand {
public:
    ChangeStateCommand(IStateManager& state_manager) : m_state_manager(state_manager) {};
protected:
    IStateManager m_state_manager;
};



