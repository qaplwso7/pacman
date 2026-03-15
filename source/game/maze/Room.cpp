#include "Room.h"
#include "IRoomSide.h"
#include "../../utils/config/GameConfig.h"

void Room::set_side(Direction side, std::unique_ptr<IRoomSide>&& ptr_side) {
    if(side == INVALID) throw std::invalid_argument("Invalid side direction!");

    m_sides[side] = std::move(ptr_side);
    m_sides[side]->prepare_for_drawing();
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
