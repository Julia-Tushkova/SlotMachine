#include <SDL.h>
#include <iostream>
#include "Game.h"

int main(int argc, char* argv[]) {
    srand(time(0));
    Game game;
    if (game.init("Slot Machine", 800, 600)) {
        game.run();
    }
    return 0;
}

