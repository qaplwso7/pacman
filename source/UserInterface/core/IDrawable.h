#pragma once

#include <SFML/Graphics.hpp>

class IDrawable {
public:
    virtual void draw_into(sf::RenderWindow& window) = 0;
    virtual ~IDrawable() = default;
};
