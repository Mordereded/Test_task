#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape {
public:
    Circle(int radius);

    std::vector<std::pair<int, int>> get_cords() override;
    ShapeType GetType() override;

private:
    int radius;
    const int DEFAULT_VALUE = 200;
};

#endif // CIRCLE_H