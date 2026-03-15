#include "SelectState.h"

#include "../../utils/config/GameConfig.h"

SelectState::SelectState(IStateManager &state_manager, const sf::VideoMode &video_mode, const std::string &window_title)
    : IState(state_manager),
    IWindowKeeper(video_mode, window_title),
    m_menu(std::make_unique<Menu>(state_manager)) {}

bool SelectState::do_step() {
    event_handling();
    update();
    render();
    return true;
}


