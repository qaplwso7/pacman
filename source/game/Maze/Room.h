#pragma once

#include "../../UserInterface/core/IDrawable.h"
#include <array>
#include <memory>

class IRoomSide;

class Room : public IDrawable {
public:
    enum Direction { INVALID = -1, LEFT, RIGHT, UP, DOWN };

    explicit Room(float size);

    float get_size() const noexcept;
    void set_position(const sf::Vector2f& position);
    sf::Vector2f get_position() const noexcept;

    void set_side(Direction side, std::shared_ptr<IRoomSide> ptr_side);
    std::shared_ptr<IRoomSide> get_side(Direction side) const noexcept;
    Direction get_direction(const IRoomSide* ptr_side) const noexcept;

    void draw_into(sf::RenderWindow& window) override;

private:
    sf::RectangleShape m_rectangle;
    std::array<std::shared_ptr<IRoomSide>, 4> m_sides;
};