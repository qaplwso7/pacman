#pragma once

#include "../core/IState.h"
#include "../IWindowKeeper.h"
#include "../../UserInterface/Elements/Menu.h"
#include <memory>

class SelectState : public IState, public IWindowKeeper {
public:
    SelectState(IStateManager& state_manager, const sf::VideoMode& video_mode, const std::string& window_title);
    bool do_step() override;

private:
    void event_handling() override;
    void update() override;
    void render() override;

    std::unique_ptr<Menu> m_menu;
};