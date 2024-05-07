#include "Quadrilateral.h"

Quadrilateral::Quadrilateral(int AB, int AC, int AD, int BC)
    : AB(AB), AC(AC), AD(AD), BC(BC) {}

std::vector<std::pair<int, int>> Quadrilateral::get_cords() {
    return {
        {0, 0}, {AB, 0},
        {AB + BC, AC}, {AD, AC}
    };
}

ShapeType Quadrilateral::GetType() {
    return ShapeType::quadrilateral;
}