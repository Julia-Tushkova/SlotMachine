#include "WinState.h"
#include "Game.h"
#include "WaitingState.h"

WinState::WinState(int score) : score(score) {}

void WinState::handleEvents(Game* game, SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        game->getStateMachine()->changeState(new WaitingState());
    }
}

void WinState::update(Game* game) {
    game->getScoreDisplay()->setScore((int)(score / 10) * 10);
}

void WinState::render(Game* game) {

    game->getScoreDisplay()->render(game->getRenderer());

    SDL_SetRenderDrawColor(game->getRenderer(), 128, 80, 194, 255); // Красный цвет

    switch (score)
    {
    case 51:
    {
        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 250, 355);
        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 550, 355);
        
        break;
    }
    case 52:
    {
        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 250, 125);
        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 550, 125);
        break;
    }
    case 102:
    {
        SDL_RenderDrawLine(game->getRenderer(), 200, 125, 600, 125);
        break;
    }
    case 101:
    {
        SDL_RenderDrawLine(game->getRenderer(), 200, 240, 600, 240);
        break;
    }
    case 100:
    {
        SDL_RenderDrawLine(game->getRenderer(), 200, 355, 600, 355);
        break;
    }
    case 151:
    {
        SDL_RenderDrawLine(game->getRenderer(), 200, 355, 600, 355);

        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 250, 355);
        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 550, 355);
        break;
    }
    case 152:
    {
        SDL_RenderDrawLine(game->getRenderer(), 200, 355, 600, 355);

        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 250, 125);
        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 550, 125);
        break;
    }
    case 153:
    {
        SDL_RenderDrawLine(game->getRenderer(), 200, 125, 600, 125);

        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 250, 355);
        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 550, 355);
        break;
    }
    case 154:
    {
        SDL_RenderDrawLine(game->getRenderer(), 200, 125, 600, 125);

        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 250, 125);
        SDL_RenderDrawLine(game->getRenderer(), 400, 240, 550, 125);
        break;
    }
    default:
        break;
    }

}
