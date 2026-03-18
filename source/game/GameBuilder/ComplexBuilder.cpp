#include "ComplexBuilder.h"
#include "../Maze/RoomSide/Wall.h"
#include "../Maze/RoomSide/Pass.h"

#include <iostream>

void ComplexBuilder::create_rooms() {
    size_t columns = static_cast<size_t>(m_width / m_room_size);
    size_t rows = static_cast<size_t>(m_height / m_room_size);
    float indent_x = (m_width - columns * m_room_size) / 2.0f;
    float indent_y = (m_height - rows * m_room_size) / 2.0f;

    m_rooms_grid.resize(rows);
    for (auto& row : m_rooms_grid)
        row.resize(columns, nullptr);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if (i % 2 == 0 && j % 2 == 0) {
                m_rooms_grid[i][j] = nullptr;
                continue;
            }
            auto room = std::make_shared<Room>(m_room_size);
            sf::Vector2f position = {
                indent_x + j * m_room_size + m_room_size / 2.0f,
                indent_y + i * m_room_size + m_room_size / 2.0f
            };
            room->set_position(position);
            m_rooms.push_back(room);
            m_rooms_grid[i][j] = room;
            std::cout << m_room_size << " " << m_room_size << std::endl;
        }
    }
}

void ComplexBuilder::set_rooms_sides() {
    size_t rows = m_rooms_grid.size();
    size_t columns = m_rooms_grid[0].size();

    for(size_t i = 0; i < rows; ++i) {
        for(size_t j = 0; j < columns; ++j) {
            auto room = m_rooms_grid[i][j];
            if(!room)
                continue;
            if(j + 1 < columns && m_rooms_grid[i][j + 1]) {
                auto right_room = m_rooms_grid[i][j + 1];
                auto pass = std::make_shared<Pass>(room, right_room);
                room->set_side(Room::RIGHT, pass);
                right_room->set_side(Room::LEFT, pass);
            }
            if(i + 1 < rows && m_rooms_grid[i + 1][j]) {
                auto down_room = m_rooms_grid[i + 1][j];
                auto pass = std::make_shared<Pass>(room, down_room);
                room->set_side(Room::DOWN, pass);
                down_room->set_side(Room::UP, pass);
            }
        }
    }

    for(size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            auto room = m_rooms_grid[i][j];
            if(!room)
                continue;
            if(!room->get_side(Room::LEFT))
                room->set_side(Room::LEFT, std::make_shared<Wall>(room));
            if(!room->get_side(Room::RIGHT))
                room->set_side(Room::RIGHT, std::make_shared<Wall>(room));
            if(!room->get_side(Room::UP))
                room->set_side(Room::UP, std::make_shared<Wall>(room));
            if(!room->get_side(Room::DOWN))
                room->set_side(Room::DOWN, std::make_shared<Wall>(room));
        }
    }
}
