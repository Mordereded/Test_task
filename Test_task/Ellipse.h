#pragma once
#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"

class Ellipse : public Shape {
public:
    Ellipse(int radiusX = 70, int radiusY = 60);

    std::vector<std::pair<int, int>> get_cords() override;
    ShapeType GetType() override;

private:
    int radiusX, radiusY;
    const int DEFAULT_VALUE = 50;
};

#endif // ELLIPSE_H