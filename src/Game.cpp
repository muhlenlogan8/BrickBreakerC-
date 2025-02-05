#include "../include/Game.h"
#include <iostream>

// Screen dimensions
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

// Constructor: Initialize SDL and create the game window and renderer
Game::Game() : box(100, 100, 50) {
    // Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        isRunning = false;
    } else {
        // Create an SDL window at the center of the screen
        window = SDL_CreateWindow("Brick Breaker", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        
        if (!window) { // Check if window creation failed
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            isRunning = false;
            return;
        }

        // Create an SDL renderer for the window with hardware acceleration
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (!renderer) { // Check if renderer creation failed
            std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            isRunning = false;
            return;
        }

        isRunning = true; // Set the flag to true to keep the game running if everything is successful
    }
}

// Destructor: Free resources and quit SDL when the game ends
Game::~Game() {
    SDL_DestroyRenderer(renderer); // Destroy (free) the renderer
    SDL_DestroyWindow(window); // Destroy (free) the window
    SDL_Quit();
}

// Run the game (main game loop)
void Game::run() {
    Uint32 lastTime = SDL_GetTicks(); // Get the current time in milliseconds

    while (isRunning) {
        Uint32 currentTime = SDL_GetTicks(); // Get the current time in milliseconds
        float deltaTime = (currentTime - lastTime) / 1000.0f; // Calculate the time difference in seconds
        lastTime = currentTime; // Update the last time

        processInput(); // Handle user inputs
        update(deltaTime); // Update game objects
        render(); // Draw the game scene
    }
}

// Handles user inputs
void Game::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }
    }

    // Read keyboard state
    const Uint8* keyState = SDL_GetKeyboardState(NULL);
    box.handleKeyState(keyState, 0.016f);  // Assuming ~60 FPS (deltaTime = 1/60)
}


// Updates game objects
void Game::update(float deltaTime) {
    const Uint8* keyState = SDL_GetKeyboardState(NULL); // Get the current state of the keyboard
    box.handleKeyState(keyState, deltaTime); // Continuously process key state
}

// Draws the game scene
void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set the color to black
    SDL_RenderClear(renderer); // Clear the renderer with the current draw color

    box.render(renderer); // Draw the box

    SDL_RenderPresent(renderer); // Present the renderer (draw the frame)
}