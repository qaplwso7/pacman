#include "ContextManager.h"

void ContextManager::reset(std::unique_ptr<GameContext> context) {
    while(!m_contexts.empty())
        m_contexts.pop();
    m_initial_context = std::move(context);
    m_contexts.push(m_initial_context->clone());
}

GameContext& ContextManager::get_current_context() {
    return* m_contexts.top();
}

void ContextManager::save_current_context() {
    m_contexts.push(m_contexts.top()->clone());
}

void ContextManager::restore_previous_context() {
    if(m_contexts.size() > 1)
        m_contexts.pop();
    else m_contexts.top() = m_initial_context->clone();
}
