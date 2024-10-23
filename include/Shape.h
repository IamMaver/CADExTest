//
// Created by User on 23.10.2024.
//

#ifndef CADEXTEST_SHAPE_H
#define CADEXTEST_SHAPE_H

#include "Point.h"

class Shape {
private:
    Point _coord;
public:
    Shape(Point p = {0, 0, 0}) : _coord(p) {} //In this task will not be initialized with other values

    virtual Point getPoint(double t) const=0;

    virtual Point getDerivative(double t) const=0;

    virtual ~Shape() = default;

};

#endif //CADEXTEST_SHAPE_H
