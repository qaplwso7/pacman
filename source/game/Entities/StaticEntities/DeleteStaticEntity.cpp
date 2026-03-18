#include "DeleteStaticEntity.h"
#include "../../GameContext/GameContext.h"

DeleteStaticEntity::DeleteStaticEntity(IStaticEntity *ptr_entity)
    : m_ptr_entity(ptr_entity) {}

void DeleteStaticEntity::handle(GameContext &context) {
    auto& statics_objects = context.static_objects;
    for(size_t i = 0; i < statics_objects.size(); ++i) {
        if(statics_objects[i].get() == m_ptr_entity) {
            statics_objects.erase(statics_objects.begin() + i);
            break;
        }
    }
}
