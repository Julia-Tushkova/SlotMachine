#pragma once
#include "State.h"

class WinState : public State {
public:
    WinState(int score);
    void handleEvents(Game* game, SDL_Event& event) override;
    void update(Game* game) override;
    void render(Game* game) override;

private:
    int score;
};