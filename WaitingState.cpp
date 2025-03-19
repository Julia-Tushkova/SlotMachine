#include "WaitingState.h"
#include "Game.h"
#include "SpinningState.h"

void WaitingState::handleEvents(Game* game, SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);

        if (game->getStartButton()->isClicked(x, y)) {
            game->getStateMachine()->changeState(new SpinningState());
        }
    }
}

void WaitingState::update(Game* game) {}

void WaitingState::render(Game* game) { game->getReelManager()->render(game->getRenderer()); }
