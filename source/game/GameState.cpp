#include "GameState.h"

#include <iostream>
#include "../utils/config/GameConfig.h"
#include "../application/states/ExitState.h"

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
    while (auto event = m_window.pollEvent()) {
        if (event.value().is<sf::Event::Closed>()) {
            m_window.close();
        }
    }
}

void GameState::update() {
    for (auto& obj : m_context_manager->get_current_context().dynamic_objects) {
        obj->action();
        obj->prepare_for_drawing();
    }
    for (auto& obj : m_context_manager->get_current_context().static_objects)
        obj->prepare_for_drawing();
    m_context_manager->get_current_context().pacman.prepare_for_drawing();
}

void GameState::render() {
    m_window.clear(config::GAME_COLOR_BACKGROUND_INGAME);
    m_maze->draw_into(m_window);
    for (auto& obj : m_context_manager->get_current_context().static_objects)
        obj->draw_into(m_window);
    for (auto& obj : m_context_manager->get_current_context().dynamic_objects)
        obj->draw_into(m_window);
    m_context_manager->get_current_context().pacman.draw_into(m_window);
    m_window.display();
}

