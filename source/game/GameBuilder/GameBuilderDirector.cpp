#include "GameBuilderDirector.h"


GameBuilderDirector::GameBuilderDirector(std::unique_ptr<IGameBuilder> ptr_builder, sf::VideoMode mode,
    std::string window_title, float dynamic_object_ratio) {
}

std::unique_ptr<GameState> GameBuilderDirector::build(StateManager &state_manager) {

}
