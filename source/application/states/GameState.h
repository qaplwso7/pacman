#pragma once

#include <iostream>

#include "../core/IState.h"
#include "../IWindowKeeper.h"

class IStateManager;

class GameState : public IState, public IWindowKeeper {
public:
    GameState(const IStateManager& state_manager, const sf::VideoMode& video_mode, const sf::Window& window_title);

    bool do_step() override {
        std::cout << "Game state" << std::endl;
        event_handling();
        update();
        render();
        return true;
    }

    void event_handling() override;
    void update() override;
    void render() override;
};

