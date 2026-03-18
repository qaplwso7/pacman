#include "Menu.h"
#include <memory>

#include "../../Game/GameBuilder/SimpleBuilder.h"
#include "../../Game/GameBuilder/ComplexBuilder.h"
#include "../../UserInterface/commands/ExitCommand.hpp"
#include "../../UserInterface/commands/GameCommand.h"

Menu::Menu(IStateManager &state_manager) : m_state_manager(state_manager) {
    const float window_size = static_cast<float>(config::SELECT_LEVEL_VIDEO_MODE.size.x);
    const float indent_left = (window_size - config::BUTTON_SIZE.x) / 2.0f;

    std::array<float, config::BUTTON_COUNT> pos_y;
    for(size_t i = 0; i < config::BUTTON_COUNT; i++) {
        if(i == 0)
            pos_y[i] = config::BUTTON_FIRST_Y_OFFSET;
        else pos_y[i] = pos_y[i - 1] + config::BUTTON_VERTICAL_SPACING;
    }

    std::array<std::string, config::BUTTON_COUNT> text{
        config::BUTTON_TEXT_EASY, config::BUTTON_TEXT_MEDIUM,
        config::BUTTON_TEXT_HARD, config::BUTTON_TEXT_EXIT
    };

    auto cmd_exit = std::make_unique<ExitCommand>(m_state_manager);
    auto builder_easy = std::make_unique<GameBuilderDirector>(std::make_unique<SimpleBuilder>(),
        config::GAME_VIDEO_MODE, config::EASY_GAME_TITLE, config::EASY_GAME_ENEMY_RATIO);
    auto cmd_easy = std::make_unique<GameCommand>(m_state_manager, std::move(builder_easy));
    auto builder_medium = std::make_unique<GameBuilderDirector>(std::make_unique<SimpleBuilder>(),
        config::GAME_VIDEO_MODE, config::MEDIUM_GAME_TITLE, config::MEDIUM_GAME_ENEMY_RATIO);
    auto cmd_medium = std::make_unique<GameCommand>(m_state_manager, std::move(builder_medium));
    auto builder_hard = std::make_unique<GameBuilderDirector>(std::make_unique<ComplexBuilder>(),
        config::GAME_VIDEO_MODE, config::HARD_GAME_TITLE, config::HARD_GAME_ENEMY_RATIO);
    auto cmd_hard = std::make_unique<GameCommand>(m_state_manager, std::move(builder_hard));

    m_buttons[0].set({indent_left, pos_y[0]}, config::BUTTON_SIZE, text[0], config::BUTTON_FONT_SIZE, std::move(cmd_easy));
    m_buttons[1].set({indent_left, pos_y[1]}, config::BUTTON_SIZE, text[1], config::BUTTON_FONT_SIZE, std::move(cmd_medium));
    m_buttons[2].set({indent_left, pos_y[2]}, config::BUTTON_SIZE, text[2], config::BUTTON_FONT_SIZE, std::move(cmd_hard));
    m_buttons[3].set({indent_left, pos_y[3]}, config::BUTTON_SIZE, text[3], config::BUTTON_FONT_SIZE, std::move(cmd_exit));
}

void Menu::process_mouse(sf::Vector2f position, bool is_pressed) {
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

void Menu::draw_into(sf::RenderWindow& window) {
    for (auto& ptr_button : m_buttons)
        ptr_button.draw_into(window);
}


