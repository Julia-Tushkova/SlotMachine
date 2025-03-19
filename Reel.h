#pragma once
#include <SDL.h>
#include <vector>
#include <cmath>
#include "TextureManager.h"

class Reel {
public:
    Reel(std::vector<int> symbols, int x, int y, SDL_Renderer* renderer, float maxSpeed);
    void update();
    void render(SDL_Renderer* renderer);
    void startSpinning();
    void stopSpinning();
    bool isSpinning() const;
    int getVisibleSymbol(int row) const; // Òåïåðü âîçâðàùàåò ÷èñëî

private:
    std::vector<int> symbolValues; // 1 - êðóã, 2 - êâàäðàò, 3 - òðåóãîëüíèê, 4 - çâåçäà
    std::vector<SDL_Texture*> textures;
    SDL_Rect slots[4];
    int currentIndex;
    bool spinning;
    bool accelerating;
    bool decelerating;
    float maxSpeed;
    float currentSpeed;
    float offsetY;
};
