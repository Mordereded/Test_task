#include "Triangle.h"
#include <cmath>

Triangle::Triangle(int AB, int AC, int BC)
    : AB((AB > 0 && AC + BC > AB) ? AB : DEFAULT_VALUE),
    AC((AC > 0 && AB + BC > AC) ? AC : DEFAULT_VALUE),
    BC((BC > 0 && AB + AC > BC) ? BC : DEFAULT_VALUE) {}

std::vector<std::pair<int, int>> Triangle::get_cords() {
    std::vector<std::pair<int, int>> points;
    int xA = 0, yA = 0;                                 // Вершина A
    int xB = AB, yB = 0;                                // Вершина B
    int xC = (BC * BC + AC * AC - AB * AB) / (2 * BC),  // Вершина C
        yC = std::sqrt(AC * AC - xC * xC);

    points.emplace_back(std::make_pair(xA, yA));
    points.emplace_back(std::make_pair(xB, yB));
    points.emplace_back(std::make_pair(xC, yC));
    return points;
}

ShapeType Triangle::GetType() {
    return ShapeType::triangle;
}