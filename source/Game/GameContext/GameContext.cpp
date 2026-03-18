#include "GameContext.h"

std::unique_ptr<GameContext> GameContext::clone() const {
    auto context = std::make_unique<GameContext>();
    context->state = state;
    context->pacman = pacman;
    for(const auto& dynamic_obj : dynamic_objects)
        context->dynamic_objects.push_back(dynamic_obj->clone());
    for(const auto& static_obj : static_objects)
        context->static_objects.push_back(static_obj->clone());

    return context;
}
