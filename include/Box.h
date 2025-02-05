#ifndef BOX_H
#define BOX_H

#include <SDL2/SDL.h>

class Box {
    public:
        Box(int x, int y, int size); // Constructor
        void handleKeyState(const Uint8* state, float deltaTime); // Handles user inputs
        void render(SDL_Renderer* renderer); // Draws the box

    private:
        float x, y; // Box position
        int size; // size
};

#endif