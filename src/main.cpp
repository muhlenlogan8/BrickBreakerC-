#include "../include/Game.h"

int SDL_main(int argc, char* argv[]) { // SDL expects "SDL_main" instead of "main" on some systems
    Game game;
    game.run();
    return 0;
}