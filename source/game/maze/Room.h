#pragma once

#include "../../user_interface/core/IDrawable.h"

#include <array>
class IRoomSide;

class Room : public IDrawable {
public:
    enum Direction { INVALID = -1, LEFT, RIGHT, UP, DOWN };

    // Запрещаем копирование (можно разрешить позже, если нужно)
    Room(const Room&) = delete;
    Room& operator=(const Room&) = delete;

    // Разрешаем перемещение (опционально)
    Room(Room&&) = default;
    Room& operator=(Room&&) = default;

    Room(float size) : m_rectangle({size, size}) { m_rectangle.setOrigin({size / 2, size / 2}); };

    float get_size() const noexcept{ return m_rectangle.getSize().x; };
    void set_position(const sf::Vector2f& position) { m_rectangle.setPosition(position); };
    sf::Vector2f get_position() const noexcept { return m_rectangle.getPosition(); };

    void set_side(Direction side, std::unique_ptr<IRoomSide>&& ptr_side);
    IRoomSide* get_side(Direction side) const noexcept { return m_sides[side].get(); };
    Direction get_direction(IRoomSide* ptr_side) const noexcept;

    void draw_into(sf::RenderWindow &window) override;

private:
    sf::RectangleShape m_rectangle;
    std::array<std::unique_ptr<IRoomSide>, 4> m_sides;
};
