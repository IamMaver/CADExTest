//
// Created by User on 23.10.2024.
//

#ifndef CADEXTEST_POINT_H
#define CADEXTEST_POINT_H

#include<cmath>

//this class is used to represent points and vectors.
//the Point class is described somewhat redundantly, there is some violation of the YAGNI principles
class Point {
private:
    double _x, _y, _z;
public:
    Point(double x = 0, double y = 0, double z = 0) : _x(x), _y(y), _z(z) {}

    inline double getX() const {
        return _x;
    }

    inline double getY() const {
        return _y;
    }

    inline double getZ() const {
        return _z;
    }

    inline void setX(double x) {
        _x = x;
    }

    inline void setY(double y) {
        _y = y;
    }

    inline void setZ(double z) {
        _z = z;
    }

    inline void setCoordinates(double x, double y, double z) {
        _x = x;
        _y = y;
        _z = z;
    }
};

#endif //CADEXTEST_POINT_H