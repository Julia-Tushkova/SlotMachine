#include "ReelManager.h"

ReelManager::ReelManager(SDL_Renderer* renderer) {
    std::vector<int> symbols1 = { 1, 2, 3, 4, 2, 3 }; // Барабан 1
    std::vector<int> symbols2 = { 4, 3, 2, 1, 3, 2 }; // Барабан 2
    std::vector<int> symbols3 = { 2, 4, 3, 1, 2, 4 }; // Барабан 3


    reels.push_back(new Reel(symbols1, 200, 100, renderer, 0.5));
    reels.push_back(new Reel(symbols2, 350, 100, renderer, 0.3));
    reels.push_back(new Reel(symbols3, 500, 100, renderer, 0.7));
}

ReelManager::~ReelManager() {
    for (auto reel : reels) {
        delete reel;
    }
}

void ReelManager::startSpinning() {
    for (auto reel : reels) {
        reel->startSpinning();
    }
}

void ReelManager::stopSpinning() {
    for (auto reel : reels) {
        reel->stopSpinning();
    }
}

void ReelManager::update() {
    for (auto reel : reels) {
        reel->update();
    }
}

void ReelManager::render(SDL_Renderer* renderer) {
    for (auto reel : reels) {
        reel->render(renderer);
    }
}

bool ReelManager::allReelsStopped() {
    for (auto reel : reels) {
        if (reel->isSpinning()) return false;
    }
    return true;
}

int ReelManager::calculateWin() {
    if (reels.empty()) return 0;

    int score = 0;
    int matrix[3][3]; // Матрица символов

    // Заполняем матрицу значениями
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            matrix[row][col] = reels[col]->getVisibleSymbol(row);
        }
    }

    // Проверка горизонтальных линий (100 очков)
    for (int row = 0; row < 3; row++) {
        if (matrix[row][0] == matrix[row][1] && matrix[row][1] == matrix[row][2]) {
            score += 100 + row;
        }
    }

    // Проверка "треугольника" (50 очков)
    if (matrix[1][1] == matrix[0][0] && matrix[1][1] == matrix[0][2]) score += 50 + 1; // Верхний треугольник
    if (matrix[1][1] == matrix[2][0] && matrix[1][1] == matrix[2][2]) score += 50 + 2; // Нижний треугольник

    return score;
}