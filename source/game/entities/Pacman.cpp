#include "Pacman.h"
#include "../../utils/config/GameConfig.h"

Pacman::Pacman() {
    float radius = config::GAME_PACMAN_SIZE / 2.0f;
    m_circle.setRadius(radius);
    m_circle.setFillColor(config::GAME_COLOR_PACMAN);
    m_circle.setOrigin({radius, radius});
}

void Pacman::draw_into(sf::RenderWindow &window) {
    window.draw(m_circle);
}

void Pacman::prepare_for_drawing() {
    m_circle.setPosition(m_ptr_room->get_position());
}

void Pacman::move(Room::Direction direction) {
    m_ptr_room->get_side(direction)->enter(this);
}
