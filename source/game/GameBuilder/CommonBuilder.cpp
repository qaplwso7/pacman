#include "CommonBuilder.h"

#include <algorithm>
#include <random>

#include "../GameState.h"
#include "../Entities/Pacman.h"
#include "../Entities/DynamicEntities/Enemy.h"
#include "../Entities/StaticEntities/Food.h"

CommonBuilder::~CommonBuilder() {}

void CommonBuilder::create_context(float dynamic_objects_ratio) {
    std::vector<Room*> available_rooms;
    for(const auto& room : m_rooms) {
        available_rooms.push_back(room.get());
    }

    static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
    std::shuffle(available_rooms.begin(), available_rooms.end(), rng);

    Pacman pacman;
    pacman.set_location(available_rooms.back());
    available_rooms.pop_back();
    m_context.pacman = std::move(pacman);

    size_t total_remaining_rooms = available_rooms.size();
    size_t total_enemies = static_cast<size_t>(total_remaining_rooms * dynamic_objects_ratio);
    if(total_remaining_rooms < total_enemies) total_enemies = total_remaining_rooms;

    for(size_t i = 0; i < total_enemies; i++) {
        auto enemy = std::make_unique<Enemy>();
        enemy->set_location(available_rooms.back());
        available_rooms.pop_back();
        m_context.dynamic_objects.push_back(std::move(enemy));
    }

    while(!available_rooms.empty()) {
        auto food = std::make_unique<Food>();
        food->set_location(available_rooms.back());
        available_rooms.pop_back();
        m_context.static_objects.push_back(std::move(food));
    }
}

void CommonBuilder::create_state(IStateManager& state_manager, sf::VideoMode mode, std::string window_title) {
    m_game_state = std::make_unique<GameState>(state_manager, mode, window_title);
}

void CommonBuilder::set_all_to_state() {
    if(!m_game_state) return;
    m_game_state->set_maze(std::move(std::make_unique<Maze>(std::move(m_rooms))));
    m_game_state->set_context(std::move(std::make_unique<GameContext>(std::move(m_context))));
}

std::unique_ptr<GameState> CommonBuilder::get_game() {
    return std::move(m_game_state);
}
