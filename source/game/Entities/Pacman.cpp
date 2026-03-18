#include "Pacman.h"

#include "LostGame.h"
#include "../../Utils/config/GameConfig.h"
#include "DynamicEntities/Enemy.h"
#include "StaticEntities/DeleteStaticEntity.h"
#include "StaticEntities/Food.h"

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

std::unique_ptr<IGameEvent> Pacman::visit(Food* ptr_food) {
    if(ptr_food->get_location() != this->get_location())
        return {};
    return std::make_unique<DeleteStaticEntity>(ptr_food);
}

std::unique_ptr<IGameEvent> Pacman::visit(Enemy* ptr_enemy) {
    if(ptr_enemy->get_location() != this->get_location())
        return {};
    return std::make_unique<LostGame>();
}
