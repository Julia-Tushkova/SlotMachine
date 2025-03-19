#pragma once
#include <SDL.h>

class Game;

class State {
public:
    virtual ~State() = default;
    virtual void handleEvents(Game* game, SDL_Event& event) = 0;
    virtual void update(Game* game) = 0;
    virtual void render(Game* game) = 0;
};
