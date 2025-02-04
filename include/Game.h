#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

class Game {
    public:
        Game();
        ~Game();
        void run();
    
    private:
        void processInput();
        void update();
        void render();

        bool isRunning;
        SDL_Window* window;
        SDL_Renderer* renderer;
};

#endif