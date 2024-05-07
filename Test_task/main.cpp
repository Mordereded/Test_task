#include <SDL.h>
#include "Window.h"
#include "Circle.h"
#include "Ellipse.h"
#include "Square.h"
#include "Quadrilateral.h"
#include "Triangle.h"


int main(int argc, char* argv[]) {
    {
    Window window(1000, 1200);
    window.Render(std::make_unique<Ellipse>(100, 200, 150, 300).get());

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                window.HandleKeyPress(event.key.keysym.sym);
                break;
            }
        }
    }

    return 0;
}