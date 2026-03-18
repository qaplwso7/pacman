#include "SimpleBuilder.h"
#include "../maze/RoomSide/Wall.h"
#include "../maze/RoomSide/Pass.h"
#include <iostream>

void SimpleBuilder::create_rooms() {
    std::cout << "create_rooms()" << std::endl;
    size_t rows = static_cast<size_t>(m_height / m_room_size);
    size_t columns = static_cast<size_t>(m_width / m_room_size);
    float indent_x = (m_width - m_room_size * columns) / 2.0f;
    float indent_y = (m_height - m_room_size * rows) / 2.0f;
    std::cout << "Room size: " << m_room_size << std::endl;

    m_rooms_grid.resize(rows);
    for (auto& row : m_rooms_grid) {
        row.resize(columns, nullptr);
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            auto room = std::make_shared<Room>(m_room_size);
            sf::Vector2f position = {
                indent_x + (j + 0.5f) * m_room_size,
                indent_y + (i + 0.5f) * m_room_size
            };
            room->set_position(position);
            std::cout << columns << " " << rows << std::endl;
            m_rooms.push_back(room);
            m_rooms_grid[i][j] = room;
        }
    }
}

void SimpleBuilder::set_rooms_sides() {
    size_t rows = m_rooms_grid.size();
    size_t columns = m_rooms_grid[0].size();

    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            auto ptr_room = m_rooms_grid[i][j];

            if(j == 0)
                ptr_room->set_side(Room::LEFT, std::make_shared<Wall>(ptr_room));
            else {
                auto ptr_room_left = m_rooms_grid[i][j - 1];
                auto pass = std::make_shared<Pass>(ptr_room, ptr_room_left);
                ptr_room->set_side(Room::LEFT, pass);
                ptr_room_left->set_side(Room::RIGHT, pass);
            }

            if(i == 0)
                ptr_room->set_side(Room::UP, std::make_shared<Wall>(ptr_room));
            else {
                auto up_room = m_rooms_grid[i - 1][j];
                auto pass = std::make_shared<Pass>(ptr_room, up_room);
                ptr_room->set_side(Room::UP, pass);
                up_room->set_side(Room::DOWN, pass);
            }

            if(j == columns - 1)
                ptr_room->set_side(Room::RIGHT, std::make_shared<Wall>(ptr_room));

            if(i == rows - 1)
                ptr_room->set_side(Room::DOWN, std::make_shared<Wall>(ptr_room));
        }
    }
}

