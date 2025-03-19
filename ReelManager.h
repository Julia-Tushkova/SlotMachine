#pragma once
#include <vector>
#include "Reel.h"

class ReelManager {
public:
    ReelManager(SDL_Renderer* renderer);
    ~ReelManager();

    void startSpinning();
    void stopSpinning();
    void update();
    void render(SDL_Renderer* renderer);
    bool allReelsStopped();
    int calculateWin();

private:
    std::vector<Reel*> reels;
};
