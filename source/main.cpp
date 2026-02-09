#include "../source/application/core/Application.h"

#include <SFML/Graphics.hpp>

int main() {
    /// connected SFML
    sf::RenderWindow window(sf::VideoMode({400, 300}), "TEST");
    sf::RectangleShape rect({100, 50});
    rect.setFillColor(sf::Color::Green);
    rect.setPosition({150, 125});
    while(window.isOpen()) {
        if(auto event = window.pollEvent())
            if(event->is<sf::Event::Closed>())
                window.close();

        window.clear();
        window.draw(rect);
        window.display();
    }

    Application app;
    return app.run();
}
