#include <iostream>
#include <SDL2/SDL.h>
using namespace std;


class game{
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        const int SCREEN_WIDTH;
        const int SCREEN_HEIGHT;
    public:
        // Constructor
        game() : SCREEN_WIDTH(800), SCREEN_HEIGHT(600), window(nullptr), renderer(nullptr) {
            // Initialize SDL
            if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
                exit(1);
            }

            // Create window
            window = SDL_CreateWindow("SDL2 Window",
                                      SDL_WINDOWPOS_CENTERED,
                                      SDL_WINDOWPOS_CENTERED,
                                      SCREEN_WIDTH, SCREEN_HEIGHT,
                                      SDL_WINDOW_SHOWN);
            if (window == nullptr) {
                cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
                SDL_Quit();
                exit(1);  // Exit the program if window creation failed
            }

            // Create renderer
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (renderer == nullptr) {
                cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << endl;
                SDL_DestroyWindow(window);
                SDL_Quit();
                exit(1);  // Exit the program if renderer creation failed
            }

            // Set render draw color (RGB + Alpha)
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
        }

        // Destructor to clean up resources
        ~game() {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
        }

        // Main loop
        void mainloop() {
            // Main loop flag
            bool quit = false;

            // Event handler
            SDL_Event e;

            // While application is running
            while (!quit) {
                // Handle events on queue
                while (SDL_PollEvent(&e) != 0) {
                    // User requests quit
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
                }

                // Clear the screen
                SDL_RenderClear(renderer);

                // Set render color (RGB + Alpha) for drawing (let's make it green)
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

                // Draw a filled rectangle (just as an example)
                SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
                SDL_RenderFillRect(renderer, &fillRect);

                // Update the screen
                SDL_RenderPresent(renderer);
            }
        }
};

int main() {
    game test;
    test.mainloop();
    cout << "Hello, World!" << endl;
    return 0;
}
