#include "ComplexBuilder.h"
#include "../maze/RoomSide/Wall.h"
#include "../maze/RoomSide/Pass.h"

void ComplexBuilder::create_rooms() {
    size_t rows = static_cast<size_t>(m_width / m_room_size);
    size_t columns = static_cast<size_t>(m_height / m_room_size);
    float indent_x = (m_width - rows * m_room_size) / 2.0f;
    float indent_y = (m_height - columns * m_room_size) / 2.0f;

    m_rooms_grid.resize(rows);
    for(auto& room : m_rooms_grid)
        room.resize(columns);

    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            if(i % 2 == 0 && j % 2 == 0) {
                m_rooms_grid[i][j] = nullptr;
            } else {
                auto room = std::make_shared<Room>(m_room_size);
                sf::Vector2f position = {
                    indent_x + (j * 0.5f) * m_room_size,
                    indent_y + (i + 0.5f) * m_room_size
                };
                room->set_position(position);
                m_rooms.emplace_back(room);
                m_rooms_grid[i][j] = room;
            }
        }
    }
}

void ComplexBuilder::set_rooms_sides() {
    size_t rows = m_rooms_grid.size();
    size_t columns = m_rooms_grid[0].size();

    for(size_t i = 0; i < rows; i++) {
        for(size_t j = 0; j < columns; j++) {
            auto ptr_room = m_rooms_grid[i][j];
            if(!ptr_room) continue;

            if(i % 2 == 1) {
                auto wall = std::make_shared<Wall>(ptr_room);
                ptr_room->set_side(Room::LEFT, wall);
                ptr_room->set_side(Room::RIGHT, wall);
            } else {
                if(j < columns - 1) {
                    auto ptr_room_left = m_rooms_grid[i][j + 1];
                    auto pass = std::make_shared<Pass>(ptr_room, ptr_room_left);
                    ptr_room->set_side(Room::RIGHT, pass);
                    ptr_room_left->set_side(Room::LEFT, pass);
                }
                else if(j == 0) {
                    auto wall = std::make_shared<Wall>(ptr_room);
                    ptr_room->set_side(Room::LEFT, wall);
                }
                else if(j == columns - 1) {
                    auto wall = std::make_shared<Wall>(ptr_room);
                    ptr_room->set_side(Room::RIGHT, wall);
                }
            }

            if(j % 2 == 1) {
                auto wall = std::make_shared<Wall>(ptr_room);
                ptr_room->set_side(Room::UP, wall);
                ptr_room->set_side(Room::DOWN, wall);
            } else {
                if(i < rows - 1) {
                    auto ptr_room_up = m_rooms_grid[i + 1][j];
                    auto pass = std::make_shared<Pass>(ptr_room, ptr_room_up);
                    ptr_room->set_side(Room::UP, pass);
                    ptr_room_up->set_side(Room::DOWN, pass);
                }
                else if(i == 0) {
                    auto wall = std::make_shared<Wall>(ptr_room);
                    ptr_room->set_side(Room::UP, wall);
                }
                else if(i == rows - 1) {
                    auto wall = std::make_shared<Wall>(ptr_room);
                    ptr_room->set_side(Room::DOWN, wall);
                }
            }
        }
    }
}
