#include "Game.h"
#include "WaitingState.h"

// �����������
Game::Game() : window(nullptr), renderer(nullptr), isRunning(true) {}

// ����������
Game::~Game() {
    clean();
}

// ������������� SDL2, �������� ��������
bool Game::init(const char* title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "������ ������������� SDL: " << SDL_GetError() << std::endl;
        return false;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "������ ������������� SDL_image: " << IMG_GetError() << std::endl;
        return false;
    }

    if (TTF_Init() == -1) {
        std::cerr << "������ ������������� SDL_ttf: " << TTF_GetError() << std::endl;
        return false;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "������ �������� ����: " << SDL_GetError() << std::endl;
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "������ �������� ���������: " << SDL_GetError() << std::endl;
        return false;
    }

    SDL_Surface* bgSurface = IMG_Load("assets/background.png");
    if (!bgSurface) {
        std::cerr << "������ �������� ����: " << IMG_GetError() << std::endl;
        return false;
    }
    backgroundTexture = SDL_CreateTextureFromSurface(renderer, bgSurface);
    SDL_FreeSurface(bgSurface);

    SDL_Surface* frameSurface = IMG_Load("assets/frame.png");
    if (!frameSurface) {
        std::cerr << "������ �������� ����: " << IMG_GetError() << std::endl;
        return false;
    }
    frameTexture = SDL_CreateTextureFromSurface(renderer, frameSurface);
    SDL_FreeSurface(frameSurface);

    // ������� ������� ��������
    startButton = new Button("assets/start.png", 39, 500, renderer);
    stopButton = new Button("assets/stop.png", 233, 500, renderer);
    reelManager = new ReelManager(renderer);
    scoreDisplay = new ScoreDisplay(renderer, "assets/font.ttf", 24);

    // ��������� ��������� ���������
    stateMachine.changeState(new WaitingState());

    return true;
}

// �������� ������� ����
void Game::run() {
    while (isRunning) {
        handleEvents();
        update();
        render();
    }
}

// ��������� ������� (�����, �������� ����)
void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
        stateMachine.handleEvents(this, event);
    }
}

// ���������� ������ ����
void Game::update() {
    reelManager->update();
    stateMachine.update(this);
}

// ��������� ��������� ����
void Game::render() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, backgroundTexture, nullptr, nullptr);

    reelManager->render(renderer);
    stateMachine.render(this);
    
    SDL_RenderCopy(renderer, frameTexture, nullptr, nullptr);

    startButton->render(renderer);
    stopButton->render(renderer);
    scoreDisplay->render(renderer);

    SDL_RenderPresent(renderer);
}

// ������� ��������
void Game::clean() {
    delete startButton;
    delete stopButton;
    delete reelManager;
    delete scoreDisplay;

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(frameTexture);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
