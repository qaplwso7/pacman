#pragma once
#include "../ChangeStateCommand.h"
#include "../../application/states/GameState.h"

class GameCommand : ChangeStateCommand {
public:
    GameCommand(IStateManager& state_manager) : ChangeStateCommand(state_manager) {};
    void execute() override;
};
