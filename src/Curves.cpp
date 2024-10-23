//
// Created by User on 23.10.2024.
//

#include "../include/Curves.h"

Point Circle::getPoint(double t) const {
    return {_radius * cos(t), _radius * sin(t), 0};
}

Point Circle::getDerivative(double t) const {
    return {-_radius * sin(t), _radius * cos(t), 0};
}

Point Ellipse::getPoint(double t) const {
    return {_radiusX * cos(t), _radiusY * sin(t), 0};
}

Point Ellipse::getDerivative(double t) const {
    return {-_radiusX * sin(t), _radiusY * cos(t), 0};
}

Point Helix::getPoint(double t) const {
    return {_radius * cos(t), _radius * sin(t), _step * t / (2 * M_PI)};
}

Point Helix::getDerivative(double t) const {
    return {-_radius * sin(t), _radius * cos(t), _step / (2 * M_PI)};
}