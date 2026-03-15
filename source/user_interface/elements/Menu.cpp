#include "Menu.h"

///#include "../../user_interface/commands/ExitCommand.hpp"
#include "../../user_interface/commands/GameCommand.h"

#include <iostream>
/// доработать после написания cmd (7-8 пункты)

/// заглушка
namespace {
    class ExitCommand : public ISelectCommand {
    public:
        explicit ExitCommand(IStateManager& manager) : m_manager(manager) {}
        void execute() override {
            std::cout << "Exit command executed (temporary)\n";
            // TODO: set next state to ExitState
            // m_manager.set_next_state(std::make_unique<ExitState>(m_manager));
        }
    private:
        IStateManager& m_manager;
    };

    class EasyGameCommand : public ISelectCommand {
    public:
        explicit EasyGameCommand(IStateManager& manager) : m_manager(manager) {}
        void execute() override {
            std::cout << "Easy game command executed (temporary)\n";
            // TODO: create GameState with SimpleBuilder and enemy ratio 0.0
        }
    private:
        IStateManager& m_manager;
    };

    class MediumGameCommand : public ISelectCommand {
    public:
        explicit MediumGameCommand(IStateManager& manager) : m_manager(manager) {}
        void execute() override {
            std::cout << "Medium game command executed (temporary)\n";
            // TODO: create GameState with SimpleBuilder and enemy ratio 0.03
        }
    private:
        IStateManager& m_manager;
    };

    class HardGameCommand : public ISelectCommand {
    public:
        explicit HardGameCommand(IStateManager& manager) : m_manager(manager) {}
        void execute() override {
            std::cout << "Hard game command executed (temporary)\n";
            // TODO: create GameState with ComplexBuilder and enemy ratio 0.07
        }
    private:
        IStateManager& m_manager;
    };
}

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
    auto cmd_easy = std::make_unique<EasyGameCommand>(m_state_manager);
    auto cmd_medium = std::make_unique<MediumGameCommand>(m_state_manager);
    auto cmd_hard = std::make_unique<HardGameCommand>(m_state_manager);

    m_buttons[0].set({indent_left, pos_y[0]}, config::BUTTON_SIZE, text[0], config::BUTTON_FONT_SIZE, std::move(cmd_exit));
    m_buttons[1].set({indent_left, pos_y[1]}, config::BUTTON_SIZE, text[1], config::BUTTON_FONT_SIZE, std::move(cmd_easy));
    m_buttons[2].set({indent_left, pos_y[2]}, config::BUTTON_SIZE, text[2], config::BUTTON_FONT_SIZE, std::move(cmd_medium));
    m_buttons[3].set({indent_left, pos_y[3]}, config::BUTTON_SIZE, text[3], config::BUTTON_FONT_SIZE, std::move(cmd_hard));
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


