#pragma once

#include "../core/IDrawable.h"
#include "Button.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <array>

class IStateManager;

class Menu : IDrawable {
public:
    Menu(const IStateManager& state_manager);

    void process_mouse(sf::Vector2f position, const bool& is_pressed);
    void draw_into(sf::RenderWindow &window) const override;
private:
    std::array<Button, 4> m_buttons;
};
