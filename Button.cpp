#include "Button.h"

Button::Button(const char* texturePath, int x, int y, SDL_Renderer* renderer) {
    texture = TextureManager::LoadTexture(texturePath, renderer);
    rect = { x, y, 150, 60 }; // Размер кнопки
}

void Button::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

bool Button::isClicked(int mouseX, int mouseY) {
    return (mouseX > rect.x && mouseX < rect.x + rect.w && mouseY > rect.y && mouseY < rect.y + rect.h);
}
