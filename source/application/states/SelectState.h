#pragma once

#include <iostream>

#include "../core/IState.h"
#include "../IWindowKeeper.h"
#include "../../user_interface/elements/Menu.h"

class IStateManager;

class SelectState : public IState, public IWindowKeeper {
public:
    SelectState(const IStateManager& state_manager, const sf::RenderVideo& video_mode, const sf::Window& window_title) :
    m_state_manager(state_manager), m_window(video_mode, window_title) {}

    bool do_step() override {
        std::cout << "Select state" << std::endl;
        return true;
    }

    void event_handling() override;
    void update() override;
    void render() override;

private:
    IStateManager& m_state_manager;
    std::unique_ptr<Menu> m_menu;
};