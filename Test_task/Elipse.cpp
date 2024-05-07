#include "Ellipse.h"
#include <cmath>
#include <SDL_stdinc.h>

Ellipse::Ellipse(int radiusX, int radiusY)
    : radiusX((radiusX > 0) ? radiusX : DEFAULT_VALUE),
    radiusY((radiusY > 0) ? radiusY : DEFAULT_VALUE) {}

std::vector<std::pair<int, int>> Ellipse::get_cords() {
    std::vector<std::pair<int, int>> points;
    int centerX = 0;
    int centerY = 0;

    for (int angle = 0; angle <= 360; ++angle) {
        float radians = angle * (M_PI / 180);
        int x = centerX + static_cast<int>(radiusX * std::cos(radians));
        int y = centerY + static_cast<int>(radiusY * std::sin(radians));
        points.emplace_back(std::make_pair(x, y));
    }
    return points;
}

ShapeType Ellipse::GetType() {
    return ShapeType::ellipse;
}