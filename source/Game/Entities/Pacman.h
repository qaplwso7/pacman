#pragma once

#include "IEntity.h"
#include "IVisitor.h"

class IGameEvent;

class Pacman : public IEntity, public IVisitor {
public:
    Pacman();
    void draw_into(sf::RenderWindow &window) override;
    void prepare_for_drawing() override;
    void move(Room::Direction direction);
    std::unique_ptr<IGameEvent> visit(Food* ptr_food) override;
    std::unique_ptr<IGameEvent> visit(Enemy* ptr_enemy) override;

private:
    sf::CircleShape m_circle;
};
