#pragma once
#include <SDL.h>
#include "TextureManager.h"

class Button {
public:
    Button(const char* texturePath, int x, int y, SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer);
    bool isClicked(int mouseX, int mouseY);

private:
    SDL_Texture* texture;
    SDL_Rect rect;
};
