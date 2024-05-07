#include "Window.h"
#include "Circle.h"
#include "Triangle.h"
#include "Ellipse.h"
#include "Square.h"
#include "Quadrilateral.h"

Window::Window(int height, int width) : height(height), width(width) {
    this->height = this->height < 0 ? 800 : this->height;
    this->width = this->width < 0 ? 800 : this->width;
    InitWindow();
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::Render(Shape* shape) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    std::vector<std::pair<int, int>> points = shape->get_cords();
    DrawShape(points, shape->GetType());
    SDL_RenderPresent(renderer);
}

void Window::HandleKeyPress(SDL_Keycode key) {
    std::unique_ptr<Shape> shape = nullptr;
    switch (key) {
    case SDLK_q: // “реугольник
        shape = std::make_unique<Triangle>(400, 400, 400);
        break;
    case SDLK_w: //  руг
        shape = std::make_unique<Circle>(70);
        break;
    case SDLK_e: // Ёллипс
        shape = std::make_unique<Ellipse>(100, 500);
        break;
    case SDLK_r: //  вадрат
        shape = std::make_unique<Square>(300);
        break;
    case SDLK_t: // „етырехугольник
        shape = std::make_unique<Quadrilateral>(100, 200, 150, 300);
        break;
    default:
        break;
    }
    if (shape) {
        Render(shape.get());
    }
}

void Window::InitWindow() {
    center_X = width / 2;
    center_Y = height / 2;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window = SDL_CreateWindow("Geometric Shapes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        exit(1);
    }
}

void Window::DrawShape(const std::vector<std::pair<int, int>>& points, ShapeType shapeType) {
    int offSetX = center_X;
    int offSetY = center_Y;
    switch (shapeType) {
    case ShapeType::triangle:
        SDL_RenderDrawLine(renderer, points[0].first + offSetX, points[0].second + offSetY, points[1].first + offSetX, points[1].second + offSetY);
        SDL_RenderDrawLine(renderer, points[1].first + offSetX, points[1].second + offSetY, points[2].first + offSetX, points[2].second + offSetY);
        SDL_RenderDrawLine(renderer, points[2].first + offSetX, points[2].second + offSetY, points[0].first + offSetX, points[0].second + offSetY);
        break;
    case ShapeType::circle:
        for (size_t i = 0; i < points.size(); ++i) {
            SDL_RenderDrawPoint(renderer, points[i].first + offSetX, points[i].second + offSetY);
        }
        break;
    case ShapeType::ellipse:
        for (size_t i = 0; i < points.size(); ++i) {
            SDL_RenderDrawPoint(renderer, points[i].first + offSetX, points[i].second + offSetY);
        }
        break;
    case ShapeType::square:
        for (size_t i = 0; i < points.size(); ++i) {
            size_t next = (i + 1) % points.size();
            SDL_RenderDrawLine(renderer, points[i].first + offSetX, points[i].second + offSetY, points[next].first + offSetX, points[next].second + offSetY);
        }
        break;
    case ShapeType::quadrilateral:
        for (size_t i = 0; i < points.size(); ++i) {
            size_t next = (i + 1) % points.size();
            SDL_RenderDrawLine(renderer, points[i].first + offSetX, points[i].second + offSetY, points[next].first + offSetX, points[next].second + offSetY);
        }
        break;
    }
}