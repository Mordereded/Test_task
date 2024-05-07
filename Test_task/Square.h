#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape {
public:
    Square(int sideLength);

    std::vector<std::pair<int, int>> get_cords() override;
    ShapeType GetType() override;

private:
    int sideLength;
    const int DEFAULT_VALUE = 50;
};

#endif // SQUARE_H