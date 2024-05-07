#include "Square.h"

Square::Square(int sideLength)
    : sideLength(sideLength > 0 ? sideLength : DEFAULT_VALUE) {}

std::vector<std::pair<int, int>> Square::get_cords() {
    std::vector<std::pair<int, int>> points;
    points.emplace_back(std::make_pair(100, 100)); // Top left
    points.emplace_back(std::make_pair(points[0].first + sideLength, points[0].second)); // Top right
    points.emplace_back(std::make_pair(points[1].first, points[1].second + sideLength)); // Bottom right
    points.emplace_back(std::make_pair(points[0].first, points[2].second)); // Bottom left
    return points;
}

ShapeType Square::GetType() {
    return ShapeType::square;
}