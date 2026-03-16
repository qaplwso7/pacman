#include "GameState.h"

#include <iostream>
#include "../../utils/config/GameConfig.h"

GameState::GameState(IStateManager& state_manager, const sf::VideoMode& video_mode, const std::string& window_title)
    : IState(state_manager), IWindowKeeper(video_mode, window_title),
      m_maze(nullptr), m_context_manager(nullptr) {}

void GameState::set_maze(std::unique_ptr<Maze> maze) {
    m_maze = std::move(maze);
}

void GameState::set_context(std::unique_ptr<GameContext> context) {
    m_context_manager = std::make_unique<ContextManager>();
    m_context_manager->reset(std::move(context));
}

bool GameState::do_step() {
    std::cout << "Game state" << std::endl;
    event_handling();
    update();
    render();
    return true;
}

void GameState::event_handling() {
}

void GameState::update() {
}

void GameState::render() {
}

