#pragma once

#include "../UserInterface/core/ISelectCommand.h"

#include<memory>

class IStateManager;

class ChangeStateCommand : public ISelectCommand {
public:
    ChangeStateCommand(IStateManager& state_manager) : m_state_manager(state_manager) {}

protected:
    IStateManager& m_state_manager;
};




