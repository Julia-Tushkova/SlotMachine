#include "StateMachine.h"

StateMachine::StateMachine() : currentState(nullptr) {}

StateMachine::~StateMachine() {
    delete currentState;
}

void StateMachine::changeState(State* newState) {
    if (currentState) {
        delete currentState;
    }
    currentState = newState;
}

void StateMachine::handleEvents(Game* game, SDL_Event& event) {
    if (currentState) currentState->handleEvents(game, event);
}

void StateMachine::update(Game* game) {
    if (currentState) currentState->update(game);
}

void StateMachine::render(Game* game) {
    if (currentState) currentState->render(game);
}
