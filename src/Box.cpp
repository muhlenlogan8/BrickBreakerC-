#include "../include/Box.h"
#include <iostream>

// Constructor: Initialize the box position and size
Box::Box(int x, int y, int size) : x(x), y(y), size(size) {}

// Handles user inputs
void Box::handleKeyState(const Uint8* keyState, float deltaTime) {
    const float speed = 100.0f; // Pixels per second

    // int x, y truncates and makes left and up movement faster than down and right so we make float in private Box in Box.h
    if (keyState[SDL_SCANCODE_UP]) {
        y -= speed * deltaTime;
        std::cout << "Moving UP: y = " << y << std::endl;
    }
    if (keyState[SDL_SCANCODE_DOWN]) {
        y += speed * deltaTime;
        std::cout << "Moving DOWN: y = " << y << std::endl;
    }
    if (keyState[SDL_SCANCODE_LEFT]) {
        x -= speed * deltaTime;
        std::cout << "Moving LEFT: x = " << x << std::endl;
    }
    if (keyState[SDL_SCANCODE_RIGHT]) {
        x += speed * deltaTime;
        std::cout << "Moving RIGHT: x = " << x << std::endl;
    }
}


// Draws the box
void Box::render(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set the color to red
    SDL_Rect boxRect = {x, y, size, size}; // Create a rectangle
    SDL_RenderFillRect(renderer, &boxRect); // Fill the rectangle
}