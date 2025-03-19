#pragma once
#include "State.h"

class StateMachine {
public:
    StateMachine();
    ~StateMachine();

    void changeState(State* newState);
    void handleEvents(Game* game, SDL_Event& event);
    void update(Game* game);
    void render(Game* game);

private:
    State* currentState;
};
