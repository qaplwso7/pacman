#include "Food.h"
#include "../../../Utils/config/GameConfig.h"
#include "../Pacman.h"
#include "../IVisitor.h"
#include "../../IGameEvent.h"

Food::Food() {
    float radius = config::GAME_FOOD_SIZE / 2.0f;
    m_circle.setRadius(radius);
    m_circle.setFillColor(config::GAME_FOOD_COLOR);
    m_circle.setOrigin({radius, radius});
}

void Food::draw_into(sf::RenderWindow &window) {
    window.draw(m_circle);
}

std::unique_ptr<IStaticEntity> Food::clone() const {
    return std::make_unique<Food>(*this);
}

std::unique_ptr<IGameEvent> Food::accept(IVisitor *ptr_visitor) {
    return ptr_visitor->visit(this);
}

void Food::prepare_for_drawing() {
    m_circle.setPosition(m_ptr_room->get_position());
}
