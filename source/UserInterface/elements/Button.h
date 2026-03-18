#pragma once

#include <memory>

#include "../core/IDrawable.h"
#include "../core/ISelectCommand.h"
#include "../../Utils/graphics/MyFont.h"

#include <string>
#include <SFML/Graphics.hpp>

class Button : public IDrawable {
public:
    Button() : m_text(MyFont::Instance()) {};
    void set(const sf::Vector2f& position, const sf::Vector2f& button_size,
        const std::string& text, const size_t& font_size,
        std::unique_ptr<ISelectCommand> ptr_command);
    void select();
    void unselect();
    bool is_position_in(sf::Vector2f position) const;
    void push();
    void draw_into(sf::RenderWindow& window) override;
private:
    sf::Text m_text;
    sf::RectangleShape m_rectangle;
    std::unique_ptr<ISelectCommand> m_ptr_command;
};

