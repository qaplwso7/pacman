#pragma once

#include "../../user_interface/core/IDrawable.h"
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

    Direction get_direction(IRoomSide* ptr_side) const noexcept;
    void set_side(Direction side, std::unique_ptr<IRoomSide>&& ptr_side);
    IRoomSide* get_side(Direction side) const noexcept;

    void draw_into(sf::RenderWindow& window) override;

private:
    sf::RectangleShape m_rectangle;
    std::array<std::unique_ptr<IRoomSide>, 4> m_sides;
};