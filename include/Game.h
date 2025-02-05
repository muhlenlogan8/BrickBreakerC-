#ifndef GAME_H  // Prevents multiple inclusions of this header file
#define GAME_H

#include <SDL2/SDL.h>
#include "./Box.h"

// Game class
class Game {
    public:
        Game(); // Constructor
        ~Game(); // Destructor
        void run(); // Run the game (main game loop)
    
    private:
        Box box; // Box object
        void processInput(); // Handles user inputs
        void update(float deltaTime); // Updates game objects
        void render(); // Draws the game scene

        bool isRunning; // Flag to keep the game running
        SDL_Window* window; // Pointer to the game window
        SDL_Renderer* renderer; // Pointer to the game renderer
};

#endif