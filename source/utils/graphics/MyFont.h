#pragma once

#include <SFML/Graphics.hpp>
#include <stdexcept>

#include "../config/GameConfig.h"

class MyFont {
public:
    MyFont(const MyFont&) = delete;
    MyFont& operator=(const MyFont&) = delete;
    static sf::Font& Instance() {
        static MyFont instance;
        return instance.m_font;
    }

protected:
    MyFont() {
        if(!m_font.openFromFile(config::FONT_FILE))
            throw std::runtime_error("Failed to load font!\n");
    }

private:
    sf::Font m_font;
};
