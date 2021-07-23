#include <iostream>
#include <SDL2/SDL.h>

int main(int argc, char **argv)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    
    SDL_Window *window = SDL_CreateWindow("Furrany Studio", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_RESIZABLE);
    
    SDL_Event event;
    
    std::cout << "Hello World !\n";
    
    while (1) {
        SDL_PollEvent(&event);
        
        if (event.type == SDL_QUIT) {
            break;
        }
    }
    
    SDL_DestroyWindow(window);
    
    SDL_Quit();

    return 0;
}
