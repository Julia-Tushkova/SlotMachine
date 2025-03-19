#include "ScoreDisplay.h"
#include <iostream>

ScoreDisplay::ScoreDisplay(SDL_Renderer* renderer, const std::string& fontPath, int fontSize)
    : renderer(renderer), scoreTexture(nullptr), currentScore(0) {

    font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font) {
        std::cerr << "Ошибка загрузки шрифта: " << TTF_GetError() << std::endl;
    }

    color = { 0, 15, 85 }; // Белый цвет текста
    scoreRect = { 20, 15, 200, 50 }; // Координаты на экране

    updateTexture();
}

ScoreDisplay::~ScoreDisplay() {
    SDL_DestroyTexture(scoreTexture);
    TTF_CloseFont(font);
}

void ScoreDisplay::setScore(int score) {
    currentScore = score;
    updateTexture();
}

void ScoreDisplay::updateTexture() {
    if (scoreTexture) {
        SDL_DestroyTexture(scoreTexture);
    }

    std::string text = "Score: " + std::to_string(currentScore);
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (!surface) {
        std::cerr << "Ошибка рендеринга текста: " << TTF_GetError() << std::endl;
        return;
    }
    scoreTexture = SDL_CreateTextureFromSurface(renderer, surface);
    scoreRect.w = surface->w;
    scoreRect.h = surface->h;
    SDL_FreeSurface(surface);
}

void ScoreDisplay::render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, scoreTexture, nullptr, &scoreRect);
}
