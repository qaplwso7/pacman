#pragma once

class IGameEvent;
class Food;
class Enemy;

class IVisitor {
public:
    virtual ~IVisitor() = default;
    virtual std::unique_ptr<IGameEvent> visit(Food* ptr_food) = 0;
    virtual std::unique_ptr<IGameEvent> visit(Enemy* ptr_enemy) = 0;
};
