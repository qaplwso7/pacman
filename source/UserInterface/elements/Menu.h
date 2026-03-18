#pragma once

#include "../core/IDrawable.h"
#include "Button.h"
#include "../../Utils/config/GameConfig.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <array>

class IStateManager;

class Menu : IDrawable {
public:
    explicit Menu(IStateManager& state_manager);
    void process_mouse(sf::Vector2f position, bool is_pressed);
    void draw_into(sf::RenderWindow &window) override;

private:
    std::array<Button, config::BUTTON_COUNT> m_buttons;
    IStateManager& m_state_manager;
};
