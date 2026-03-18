#pragma once

#include "../IStaticEntity.h"
#include <memory>

class Food : public IStaticEntity {
public:
    Food();

    void prepare_for_drawing() override;
    void draw_into(sf::RenderWindow& window) override;
    std::unique_ptr<IStaticEntity> clone() const override;
    std::unique_ptr<IGameEvent> accept(IVisitor *ptr_visitor) override;;

private:
    sf::CircleShape m_circle;
};
