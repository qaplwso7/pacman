#pragma once

#include "../../IGameEvent.h"

class IStaticEntity;

class DeleteStaticEntity : public IGameEvent {
public:
    DeleteStaticEntity(IStaticEntity* ptr_entity);
    void handle(GameContext& context) override;
private:
    IStaticEntity* m_ptr_entity;
};