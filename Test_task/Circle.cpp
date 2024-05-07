#include "Circle.h"
#include <cmath>
#include <SDL_stdinc.h>

Circle::Circle(int radius) : radius(radius > 0 ? radius : DEFAULT_VALUE) {}

std::vector<std::pair<int, int>> Circle::get_cords() {
    std::vector<std::pair<int, int>> points;
    int centerX = 0;
    int centerY = 0;

    for (ptrdiff_t angle = 0; angle <= 360; ++angle) {
        float radians = angle * (M_PI / 180);
        int x = centerX + static_cast<int>(radius * std::cos(radians));
        int y = centerY + static_cast<int>(radius * std::sin(radians));
        points.emplace_back(std::make_pair(x, y));
    }
    return points;
}

ShapeType Circle::GetType() {
    return ShapeType::circle;
}