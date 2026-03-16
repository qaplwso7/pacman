#pragma once

#include "GameContext.h"
#include <stack>
#include <memory>

class ContextManager {
public:
    void reset(std::unique_ptr<GameContext> context);
    GameContext& get_current_context();
    void save_current_context();
    void restore_previous_context();

private:
    std::stack<std::unique_ptr<GameContext>> m_contexts;
    std::unique_ptr<GameContext> m_initial_context;
};