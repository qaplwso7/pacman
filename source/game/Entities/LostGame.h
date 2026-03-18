#pragma once

#include "../IGameEvent.h"

class LostGame : public IGameEvent {
public:
    void handle(GameContext& context) override;
};
