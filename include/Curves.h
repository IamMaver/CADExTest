//
// Created by User on 23.10.2024.
//

#ifndef CADEXTEST_CURVES_H
#define CADEXTEST_CURVES_H

#include "Shape.h"

class Circle : public Shape {
private:
    double _radius;
public:
    Circle(double radius, Point center = {0, 0, 0}) : Shape(center), _radius(radius) {}

    Point getPoint(double t) const override;

    Point getDerivative(double t) const override;

    inline double getRadius() const {
        return _radius;
    }
};

class Ellipse : public Shape {
private:
    double _radiusX;
    double _radiusY;
public:
    Ellipse(double radiusX, double radiusY, Point center = {0, 0, 0})
            : Shape(center), _radiusX(radiusX), _radiusY(radiusY) {}

    Point getPoint(double t) const override;

    Point getDerivative(double t) const override;
};

class Helix : public Shape {
private:
    double _radius;
    double _step;
public:
    Helix(double radius, double step, Point center = {0, 0, 0})
            : Shape(center), _radius(radius), _step(step) {}

    Point getPoint(double t) const override;

    Point getDerivative(double t) const override;
};

#endif //CADEXTEST_CURVES_H