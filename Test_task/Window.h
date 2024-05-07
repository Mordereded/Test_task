
#ifndef WINDOW_H
#define WINDOW_H
#pragma once

#include <iostream>
#include <SDL.h>
#include <memory>
#include <vector>
#include <cmath>
#include <utility>
#include <string>

#include "Shape.h"

class Window {
public:
    Window(int height = 800, int width = 800);
    ~Window();

    void Render(Shape* shape);
    void HandleKeyPress(SDL_Keycode key);

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int height;
    int width;
    int center_X;
    int center_Y;

    void InitWindow();
    void DrawShape(const std::vector<std::pair<int, int>>& points, ShapeType shapeType);
};

#endif // WINDOW_H