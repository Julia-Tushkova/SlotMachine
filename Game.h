#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include "Button.h"
#include "ReelManager.h"
#include "StateMachine.h"
#include "ScoreDisplay.h"

class Game {
public:
    Game();
    ~Game();

    bool init(const char* title, int width, int height);
    void run();

    SDL_Renderer* getRenderer() { return renderer; }
    Button* getStartButton() { return startButton; }
    Button* getStopButton() { return stopButton; }
    ReelManager* getReelManager() { return reelManager; }
    StateMachine* getStateMachine() { return &stateMachine; }
    ScoreDisplay* getScoreDisplay() { return scoreDisplay; }

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;

    Button* startButton;
    Button* stopButton;
    ReelManager* reelManager;
    StateMachine stateMachine;
    ScoreDisplay* scoreDisplay;
    SDL_Texture* backgroundTexture;
    SDL_Texture* frameTexture;

    void handleEvents();
    void update();
    void render();
    void clean();
};
