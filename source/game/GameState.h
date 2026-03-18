#pragma once

#include "GameContext/ContextManager.h"
#include "GameContext/GameContext.h"
#include "Maze/Maze.h"
#include "../application/core/IState.h"
#include "../application/IWindowKeeper.h"

class IStateManager;
class ContextManager;
class GameContext;
class Maze;

class GameState : public IState, public IWindowKeeper {
public:
    GameState(IStateManager &state_manager, const sf::VideoMode &video_mode, const std::string &window_title);

    void set_maze(std::unique_ptr<Maze> maze);
    void set_context(std::unique_ptr<GameContext> context);

    bool do_step() override;
    void event_handling() override;
    void update() override;
    void render() override;

private:
    void process_key_pressed(const sf::Event::KeyPressed* ptr_event);
    void process_entities_interactions() const;

private:
    std::unique_ptr<Maze> m_maze;
    std::unique_ptr<ContextManager> m_context_manager;
};

