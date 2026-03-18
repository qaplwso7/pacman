#include "Enemy.h"
#include "../../Maze/Room.h"
#include "../../../Utils/config/GameConfig.h"
#include "../IVisitor.h"
#include "../../IGameEvent.h"

Enemy::Enemy() {
    float radius = config::GAME_ENEMY_SIZE / 2.0f;
    m_circle.setRadius(radius);
    m_circle.setFillColor(config::GAME_ENEMY_COLOR);
    m_circle.setOrigin({radius, radius});
}

void Enemy::draw_into(sf::RenderWindow &window) {
    window.draw(m_circle);
}

void Enemy::prepare_for_drawing() {
    m_circle.setPosition(m_ptr_room->get_position());
}

std::unique_ptr<IGameEvent> Enemy::accept(IVisitor* ptr_visitor) {
    return ptr_visitor->visit(this);
}

void Enemy::action() {
    if(!m_ptr_room)
        return;
    if(m_stopwatch.getElapsedTime().asMilliseconds() < (m_rng() % 500))
        return;

    auto direction = static_cast<Room::Direction>(rand() % 4);
    m_ptr_room->get_side(direction)->enter(this);
    m_stopwatch.restart();
}
