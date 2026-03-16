#pragma once

#include "IStaticEntity.h"

class Food : public IStaticEntity {
public:
    Food();

    void prepare_for_drawing() override;
    void draw_into(sf::RenderWindow &window) override;
    std::unique_ptr<IStaticEntity> clone() const override { return std::make_unique<Food>(*this); };

private:
    sf::CircleShape m_circle;
};