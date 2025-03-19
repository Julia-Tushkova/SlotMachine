#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class ScoreDisplay {
public:
    ScoreDisplay(SDL_Renderer* renderer, const std::string& fontPath, int fontSize);
    ~ScoreDisplay();

    void setScore(int score);
    void render(SDL_Renderer* renderer);

private:
    SDL_Texture* scoreTexture;
    SDL_Rect scoreRect;
    TTF_Font* font;
    SDL_Color color;
    int currentScore;
    SDL_Renderer* renderer;

    void updateTexture();
};
