#pragma once

#include <vector>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "IGameBuilder.h"

class IRoomSide;
class StateManager;
class GameState;
class Room;
class GameContext;

class CommonBuilder : public IGameBuilder {
public:
    void create_context(float dynamic_objects_ratio) override;
    void create_state(StateManager& state_manager, sf::VideoMode mode, std::string window_title);
    void set_all_to_state();
    std::unique_ptr<GameState> get_game();

protected:
    float m_width = 0.0f;
    float m_height = 0.0f;
    float m_room_size = 0.0f;
;
    GameContext m_context;
    std::unique_ptr<GameState> m_game_state;
};
