#pragma once
#include <SDL.h>
#include <vector>
#include "TextureManager.h"

class Reel {
public:
    Reel(std::vector<int> symbols, int x, int y, SDL_Renderer* renderer, float maxSpeed);
    void update();
    void render(SDL_Renderer* renderer);
    void startSpinning();
    void stopSpinning();
    bool isSpinning() const;
    int getVisibleSymbol(int row) const; // Теперь возвращает число

private:
    std::vector<int> symbolValues; // 1 - круг, 2 - квадрат, 3 - треугольник, 4 - звезда
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
