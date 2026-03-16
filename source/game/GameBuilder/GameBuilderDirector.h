#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class StateManager;
class GameState;
class IGameBuilder;

class GameBuilderDirector {
public:
    GameBuilderDirector(std::unique_ptr<IGameBuilder> ptr_builder, sf::VideoMode mode,
        std::string window_title, float dynamic_object_ratio);

    std::unique_ptr<GameState> build(StateManager& state_manager);

private:
    std::unique_ptr<IGameBuilder> m_ptr_builder;
    std::string m_title;
    sf::VideoMode m_mode;
    float m_dynamic_object_ratio = 0.0f;
};