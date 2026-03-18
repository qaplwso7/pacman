#pragma once

class GameContext;

class IGameEvent {
public:
    virtual ~IGameEvent() = default;
    virtual void handle(GameContext& context) = 0;
};