#pragma once

#include <SFML/Graphics.hpp>
#include "IGameBuilder.h"
#include "../GameState.h"
#include <memory>
#include <string>

class IStateManager;

class GameBuilderDirector {
public:
    GameBuilderDirector(std::unique_ptr<IGameBuilder>, sf::VideoMode, const std::string&, float);
    std::unique_ptr<GameState> build(IStateManager& state_manager);

private:
    std::string m_window_title;
    sf::VideoMode m_mode;
    float m_dynamic_object_ratio;
    std::unique_ptr<IGameBuilder> m_ptr_builder;
};
