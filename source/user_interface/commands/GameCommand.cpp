#include "GameCommand.h"
#include "../../application/core/IStateManager.h"
#include <iostream>

GameCommand::GameCommand(IStateManager& state_manager, std::unique_ptr<GameBuilderDirector> ptr_director)
    : ChangeStateCommand(state_manager), m_ptr_director(std::move(ptr_director)) {}

void GameCommand::execute() {
    std::cout << "Game command executed" << std::endl;
    auto game_state = m_ptr_director->build(m_state_manager);
    m_state_manager.set_next_state(std::move(game_state));
}
