#pragma once

#include <vector>
#include <string>

#include "IGameBuilder.h"
#include "../GameContext/GameContext.h"
#include "../../Utils/config/GameConfig.h"

class IRoomSide;
class IStateManager;
class GameState;
class Room;

class CommonBuilder : public IGameBuilder {
public:
    ~CommonBuilder() override;
    void create_context(float dynamic_objects_ratio) override;
    void create_state(IStateManager& state_manager, sf::VideoMode mode, std::string window_title) override;
    void set_all_to_state() override;
    std::unique_ptr<GameState> get_game() override;

protected:
    float m_width = config::GAME_VIDEO_MODE.size.x;
    float m_height = config::GAME_VIDEO_MODE.size.y;
    float m_room_size = config::ROOM_SIZE;
    std::vector<std::vector<std::shared_ptr<Room>>> m_rooms_grid;
    std::vector<std::shared_ptr<Room>> m_rooms;
    GameContext m_context;
    std::unique_ptr<GameState> m_game_state;
};
