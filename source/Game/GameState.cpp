#include "GameState.h"

#include "../application/states/SelectState.h"
#include "../application/core/IStateManager.h"
#include "IGameEvent.h"
#include "../Utils/config/GameConfig.h"

GameState::GameState(IStateManager& state_manager, const sf::VideoMode& video_mode, const std::string& window_title)
    : IState(state_manager), IWindowKeeper(video_mode, window_title) {}

void GameState::set_maze(std::unique_ptr<Maze> maze) {
    m_maze = std::move(maze);
}

void GameState::set_context(std::unique_ptr<GameContext> context) {
    m_context_manager = std::make_unique<ContextManager>();
    m_context_manager->reset(std::move(context));
}

bool GameState::do_step() {
    event_handling();
    update();
    render();
    return true;
}

void GameState::process_key_pressed(const sf::Event::KeyPressed* ptr_event) {
    if(m_context_manager->get_current_context().state == GameContext::INGAME) {
        if(ptr_event->code == config::KEY_LEFT) {
            m_context_manager->save_current_context();
            m_context_manager->get_current_context().pacman.move(Room::LEFT);
        }
        else if(ptr_event->code == config::KEY_UP) {
            m_context_manager->save_current_context();
            m_context_manager->get_current_context().pacman.move(Room::UP);
        }
        else if(ptr_event->code == config::KEY_RIGHT) {
            m_context_manager->save_current_context();
            m_context_manager->get_current_context().pacman.move(Room::RIGHT);
        }
        else if(ptr_event->code == config::KEY_DOWN) {
            m_context_manager->save_current_context();
            m_context_manager->get_current_context().pacman.move(Room::DOWN);
        }
    }

    if(ptr_event->code == sf::Keyboard::Key::Escape) {
        m_window.close();
        m_state_manager.set_next_state(std::make_unique<SelectState>(m_state_manager,
            config::SELECT_LEVEL_VIDEO_MODE, config::SELECT_LEVEL_TITLE));
    }
}

void GameState::process_entities_interactions() const {
    auto& context = m_context_manager->get_current_context();
    std::vector<std::unique_ptr<IGameEvent>> buffer;

    for(auto& food : context.static_objects)
        if(auto event = food->accept(&context.pacman))
            buffer.push_back(std::move(event));

    for(auto& enemy : context.dynamic_objects)
        if(auto event = enemy->accept(&context.pacman))
            buffer.push_back(std::move(event));

    for (auto& event : buffer)
        event->handle(context);
}

void GameState::event_handling() {
    while(const auto event = m_window.pollEvent()) {
        if(event->is<sf::Event::Closed>()) {
            m_window.close();
            m_state_manager.set_next_state(std::make_unique<SelectState>(m_state_manager, config::SELECT_LEVEL_VIDEO_MODE, config::SELECT_LEVEL_TITLE));
        }
        else if(auto ptr_event = event->getIf<sf::Event::Resized>()) {
            sf::View view = m_window.getView();
            view.setSize(sf::Vector2f(ptr_event->size));
            m_window.setView(view);
        }
        else if(auto ptr_event = event->getIf<sf::Event::KeyPressed>()) {
            if (ptr_event->control && ptr_event->code == sf::Keyboard::Key::Z) {
                m_context_manager->restore_previous_context();
            } else {
                process_key_pressed(ptr_event);
            }
        }
    }
}

void GameState::update() {
    auto& context = m_context_manager->get_current_context();

    if(context.state != GameContext::INGAME)
        return;

    for(auto& enemy : context.dynamic_objects)
        enemy->action();

    process_entities_interactions();

    if(context.static_objects.empty())
        context.state = GameContext::WIN;
}

void GameState::render() {
    if(m_context_manager->get_current_context().state == GameContext::INGAME)
        m_window.clear(config::GAME_COLOR_BACKGROUND_INGAME);
    else if(m_context_manager->get_current_context().state == GameContext::WIN)
        m_window.clear(config::GAME_COLOR_BACKGROUND_WIN);
    else
        m_window.clear(config::GAME_COLOR_BACKGROUND_LOST);

    m_maze->draw_into(m_window);

    auto& context = m_context_manager->get_current_context();

    for(const auto& food : context.static_objects)
        food->draw_into(m_window);

    for(const auto& enemy : context.dynamic_objects)
        enemy->draw_into(m_window);

    context.pacman.draw_into(m_window);

    m_window.display();
}

