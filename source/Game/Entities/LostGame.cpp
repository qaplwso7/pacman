#include "LostGame.h"
#include "../GameContext/GameContext.h"

void LostGame::handle(GameContext& context) {
    context.state = GameContext::LOST;
}
