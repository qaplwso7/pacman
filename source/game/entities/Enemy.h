#pragma once

#include <random>

#include "IDynamicEntity.h"
#include "IStaticEntity.h"

class IRoomSide;

class Enemy : public IDynamicEntity {
public:
    Enemy();
    std::unique_ptr<IDynamicEntity> clone() const override { return std::make_unique<Enemy>(*this); };
    void action() override;
    void draw_into(sf::RenderWindow &window) override;
    void prepare_for_drawing() override;

private:
    sf::CircleShape m_circle;
    sf::Clock m_stopwatch;
    std::mt19937 m_rng{std::random_device{}()};
};
