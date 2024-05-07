#pragma once
#ifndef SHAPE_H
#define SHAPE_H

#include <vector>
#include <utility>

enum ShapeType
{
    triangle,
    circle,
    ellipse,
    square,
    quadrilateral
};

class Shape {
public:
    virtual std::vector<std::pair<int, int>> get_cords() = 0;
    virtual ShapeType GetType() = 0;
    virtual ~Shape() {}
};

#endif // SHAPE_H