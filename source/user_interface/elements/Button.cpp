#include "Button.h"
#include "../../utils/graphics/MyFont.h"
#include "../../utils/config/GameConfig.h"

void Button::set(const sf::Vector2f& position, const sf::Vector2f& button_size,
                 const std::string& text, const size_t& font_size, std::unique_ptr<ISelectCommand> ptr_command) {

    m_ptr_command = std::move(ptr_command);

    m_rectangle.setPosition(position);
    m_rectangle.setSize(button_size);
    m_rectangle.setFillColor(config::BUTTON_COLOR_FILL);
    m_rectangle.setOutlineThickness(config::BUTTON_FRAME_THICKNESS);
    m_rectangle.setOutlineColor(config::BUTTON_COLOR_FRAME);

    m_text.setFont(MyFont::Instance());
    m_text.setCharacterSize(config::BUTTON_FONT_SIZE / 2.5f);
    m_text.setFillColor(config::BUTTON_COLOR_TEXT);
    m_text.setString(text);
    const sf::FloatRect text_bounds = m_text.getGlobalBounds();
    m_text.setPosition({
        (position.x + (button_size.x - text_bounds.size.x) / 2 - text_bounds.position.x),
        (position.y + (button_size.y - text_bounds.size.y) / 2 - text_bounds.position.y),
    });
}

void Button::select() { m_rectangle.setFillColor(config::BUTTON_COLOR_SELECTION); }

void Button::unselect() { m_rectangle.setFillColor(config::BUTTON_COLOR_FILL); }

bool Button::is_position_in(sf::Vector2f position) const { return m_rectangle.getGlobalBounds().contains(position); }

void Button::push() { m_ptr_command->execute(); }

void Button::draw_into(sf::RenderWindow &window) {
    window.draw(m_rectangle);
    window.draw(m_text);
}






