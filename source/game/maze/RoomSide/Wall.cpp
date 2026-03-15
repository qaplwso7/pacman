#include "Wall.h"
#include "../../../utils/config/GameConfig.h"
#include "../Room.h"

void Wall::prepare_for_drawing() {
    const sf::Vector2 pos = m_room.get_position();
    const float size = m_room.get_size();
    const std::array<sf::Vector2f, 4> corners = {
        sf::Vector2f{pos.x - size/2, pos.y - size/2},
        sf::Vector2f{pos.x + size / 2, pos.y - size/2},
        sf::Vector2f{pos.x - size/2, pos.y + size/2},
        sf::Vector2f{pos.x + size/2, pos.y + size/2}
    };

    switch(m_room.get_direction(this)) {
        case Room::Direction::UP:
            m_line[0] = sf::Vertex{corners[0], config::GAME_COLOR_WALL};
            m_line[1] = sf::Vertex{corners[1], config::GAME_COLOR_WALL};
            break;
        case Room::Direction::DOWN:
            m_line[0] = sf::Vertex{corners[2], config::GAME_COLOR_WALL};
            m_line[1] = sf::Vertex{corners[3], config::GAME_COLOR_WALL};
            break;
        case Room::Direction::LEFT:
            m_line[0] = sf::Vertex{corners[0], config::GAME_COLOR_WALL};
            m_line[1] = sf::Vertex{corners[2], config::GAME_COLOR_WALL};
            break;
        case Room::Direction::RIGHT:
            m_line[0] = sf::Vertex{corners[1], config::GAME_COLOR_WALL};
            m_line[1] = sf::Vertex{corners[3], config::GAME_COLOR_WALL};
            break;
        case Room::Direction::INVALID:
            throw std::invalid_argument("Invalid direction!");
    }
}

