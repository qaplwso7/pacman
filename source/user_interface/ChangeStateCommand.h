#pragma once

#include "../application/core/IStateManager.h"
#include "core/ISelectCommand.h"

class IStateManager;

class ChangeStateCommand : ISelectCommand {
public:
    ChangeStateCommand(IStateManager& manager) : m_state_manager(manager) {}
protected:
    IStateManager& m_state_manager;
};



