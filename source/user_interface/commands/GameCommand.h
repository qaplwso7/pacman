#pragma once
#include "../ChangeStateCommand.h"
#include "../../game/GameBuilder/GameBuilderDirector.h"
#include <memory>

class IStateManager;
class GameBuilderDirector;

class GameCommand : public ChangeStateCommand {
public:
    GameCommand(IStateManager& state_manager, std::unique_ptr<GameBuilderDirector> ptr_director);
    ~GameCommand() = default;
    void execute() override;

private:
    std::unique_ptr<GameBuilderDirector> m_ptr_director;
};
