#pragma once
#include "State.h"
#include <chrono>

class SpinningState : public State {
public:
    SpinningState();
    void handleEvents(Game* game, SDL_Event& event) override;
    void update(Game* game) override;
    void render(Game* game) override;

private:
    std::chrono::time_point<std::chrono::steady_clock> startTime; // Время начала вращения
    bool stopInitiated;
};
