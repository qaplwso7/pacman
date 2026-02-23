#include "Menu.h"

#include <winsock2.h>

#include "../../utils/config/GameConfig.hpp"

Menu::Menu(const IStateManager &state_manager) {
    /// сделать центрирование, выставить размеры и тд

    // m_buttons[0].set();
    // m_buttons[1].set();
    // m_buttons[2].set();
    // m_buttons[3].set();

}

void Menu::process_mouse(sf::Vector2f position, const bool &is_pressed) {
    for(auto& button : m_buttons) {
        if(button.is_position_in(position)) {
            button.select();
            if(is_pressed)
                button.push();
        }
        else {
            button.unselect();
        }
    }
}

void Menu::draw_into(sf::RenderWindow& window) const {
    for (const Button& ptr_button : m_buttons)
        ptr_button.draw_into(window);
}


