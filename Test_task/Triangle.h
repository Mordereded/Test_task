#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(int AB = 200, int AC = 200, int BC = 200);

    std::vector<std::pair<int, int>> get_cords() override;
    ShapeType GetType() override;

private:
    int AB, AC, BC;
    const int DEFAULT_VALUE = 200;
};

#endif // TRIANGLE_H