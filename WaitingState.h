#pragma once
#include "State.h"
#include "Button.h"

class WaitingState : public State {
public:
    void handleEvents(Game* game, SDL_Event& event) override;
    void update(Game* game) override;
    void render(Game* game) override;
};
