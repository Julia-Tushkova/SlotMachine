#include <SDL.h>
#include <iostream>
#include <windows.h>
#include "Game.h"

// Функция WinMain
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    srand(time(0));  // Инициализация генератора случайных чисел
    Game game;

    if (game.init("Slot Machine", 800, 600)) {
        game.run();
    }

    return 0;
}
