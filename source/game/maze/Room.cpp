#include "Room.h"
#include "IRoomSide.h"
#include "../../utils/config/GameConfig.h"

Room::Room(float size) : m_rectangle({size, size}) {
    m_rectangle.setOrigin(m_rectangle.getSize() / 2.0f);
    m_rectangle.setFillColor(config::GAME_COLOR_ROOM);
}

float Room::get_size() const noexcept {
    return m_rectangle.getSize().x;
}

void Room::set_position(const sf::Vector2f &position) {
    m_rectangle.setPosition(position);
}

sf::Vector2f Room::get_position() const noexcept {
    return m_rectangle.getPosition();
}

void Room::set_side(Direction side, std::unique_ptr<IRoomSide>&& ptr_side) {
    if(side == INVALID)
        throw std::invalid_argument("Invalid side direction!");
    m_sides[side] = std::move(ptr_side);
}

IRoomSide * Room::get_side(Direction side) const noexcept {
    return m_sides[side].get();
}

Room::Direction Room::get_direction(IRoomSide *ptr_side) const noexcept {
    if(m_sides[RIGHT].get() == ptr_side) return RIGHT;
    if(m_sides[LEFT].get() == ptr_side) return LEFT;
    if(m_sides[DOWN].get() == ptr_side) return DOWN;
    if(m_sides[UP].get() == ptr_side) return UP;
    return INVALID;
}

void Room::draw_into(sf::RenderWindow &window) {
    window.draw(m_rectangle);
    for(auto& side : m_sides)
        if(side)
            side->draw_into(window);
}
