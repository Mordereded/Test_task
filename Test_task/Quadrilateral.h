#pragma once
#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Shape.h"

class Quadrilateral : public Shape {
public:
    Quadrilateral(int AB, int AC, int AD, int BC);

    std::vector<std::pair<int, int>> get_cords() override;
    ShapeType GetType() override;

private:
    int AB, AC, AD, BC;
};

#endif // QUADRILATERAL_H