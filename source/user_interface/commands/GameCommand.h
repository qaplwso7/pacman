#pragma once
#include "../ChangeStateCommand.h"
#include "../../game/GameState.h"

class GameCommand : ChangeStateCommand {
public:
    GameCommand(IStateManager& state_manager) : ChangeStateCommand(state_manager) {};
    void execute() override;
};
