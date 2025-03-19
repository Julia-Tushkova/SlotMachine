#include "SpinningState.h"
#include "Game.h"
#include "WinState.h"

SpinningState::SpinningState() {
    startTime = std::chrono::steady_clock::now();
    stopInitiated = false;
}

void SpinningState::update(Game* game) {
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();
    
    if (elapsed == 0) {
        game->getReelManager()->startSpinning();
    }

    if (elapsed >= 5 && !stopInitiated) { // ������������� �������� ����� 3 ������ ��������
        game->getReelManager()->stopSpinning();
        stopInitiated = true;
    }

    // ����� ��� �������� ������������ - ��������� � WinState
    if (game->getReelManager()->allReelsStopped()) {
        int score = game->getReelManager()->calculateWin();
        game->getStateMachine()->changeState(new WinState(score));
    }   

    game->getReelManager()->update();
}

void SpinningState::render(Game* game) {
    game->getReelManager()->render(game->getRenderer());
}

void SpinningState::handleEvents(Game* game, SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);

        if (game->getStopButton()->isClicked(x, y)) {
            game->getReelManager()->stopSpinning();
            stopInitiated = true;
        }
    }
}