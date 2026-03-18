#include "GameBuilderDirector.h"
#include "IGameBuilder.h"
#include "../GameState.h"
#include <iostream>

GameBuilderDirector::GameBuilderDirector(std::unique_ptr<IGameBuilder> ptr_builder
    , sf::VideoMode mode, const std::string& window_title, float dynamic_objects_ratio)
    : m_mode(mode), m_window_title(window_title),
    m_dynamic_object_ratio(dynamic_objects_ratio),
    m_ptr_builder(std::move(ptr_builder)) {}

std::unique_ptr<GameState> GameBuilderDirector::build(IStateManager& state_manager) {
    std::cout << "Game builder director building1" << std::endl;
    m_ptr_builder->create_rooms();
    std::cout << "Game builder director building2" << std::endl;
    m_ptr_builder->set_rooms_sides();
    std::cout << "Game builder director building3" << std::endl;
    m_ptr_builder->create_context(m_dynamic_object_ratio);
    std::cout << "Game builder director building4" << std::endl;
    m_ptr_builder->create_state(state_manager, m_mode, m_window_title);
    std::cout << "Game builder director building5" << std::endl;
    m_ptr_builder->set_all_to_state();
    std::cout << "Game builder director building7" << std::endl;
    return m_ptr_builder->get_game();
}
