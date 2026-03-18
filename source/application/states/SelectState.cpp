#include "SelectState.h"

#include "../../Utils/config/GameConfig.h"
#include "../core/IStateManager.h"
#include "ExitState.h"

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

void SelectState::event_handling() {
    while(const std::optional event = m_window.pollEvent()) {
        if(event->is<sf::Event::Closed>()) {
            m_window.close();
            m_state_manager.set_next_state(std::make_unique<ExitState>(m_state_manager));
        }
        if(auto ptr_event = event->getIf<sf::Event::Resized>()) {
            sf::View view = m_window.getView();
            view.setSize(sf::Vector2f(ptr_event->size));
            m_window.setView(view);
        }
        else if(auto* mouseMoved = event->getIf<sf::Event::MouseMoved>()) {
            sf::Vector2i mousePos(mouseMoved->position.x, mouseMoved->position.y);
            m_menu->process_mouse(static_cast<sf::Vector2f>(mousePos), false);
        }
        else if(auto* mousePressed = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mousePressed->button == sf::Mouse::Button::Left) {
                sf::Vector2i mousePos(mousePressed->position.x, mousePressed->position.y);
                m_menu->process_mouse(static_cast<sf::Vector2f>(mousePos), true);
            }
        }
    }
}

void SelectState::update() {}

void SelectState::render() {
    m_window.clear(config::SELECT_LEVEL_BACKGROUND_COLOR);
    m_menu->draw_into(m_window);
    m_window.display();
}

