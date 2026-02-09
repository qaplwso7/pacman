#pragma once
#include "SFML/Graphics/RenderWindow.hpp"
#include <string>


class IWindowKeeper {
public:
    IWindowKeeper(const sf::VideoMode& video_mode, const std::string& wideo_title) :
        m_window(video_mode, wideo_title) {}
    virtual ~IWindowKeeper() = default;

protected:
    /// SelectState и GameState реализуют этот интерфейс
    virtual void event_handling() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

protected:
    sf::RenderWindow m_window;
};




