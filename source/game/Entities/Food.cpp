#include "Food.h"
#include "../../utils/config/GameConfig.h"

Food::Food() {
    float radius = config::GAME_FOOD_SIZE / 2.0f;
    m_circle.setRadius(radius);
    m_circle.setFillColor(config::GAME_FOOD_COLOR);
    m_circle.setOrigin({radius, radius});
}

void Food::draw_into(sf::RenderWindow &window) {
    window.draw(m_circle);
}

void Food::prepare_for_drawing() {
    m_circle.setPosition(m_ptr_room->get_position());
}