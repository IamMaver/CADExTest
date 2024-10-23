#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>
#include <random>
#include "../include/Curves.h"



double randomInRange(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

void SeedVector(std::vector<std::shared_ptr<Shape>> &curves, int count) {
    for (int i = 0; i < count; ++i) {
        int type = randomInRange(0, 3);  // 0 - Circle, 1 - Ellipse, 2 - Helix
        if (type == 0) {
            double radius = randomInRange(1.0, 10.0);
            curves.push_back(std::make_shared<Circle>(radius));
        } else if (type == 1) {
            double radiusX = randomInRange(1.0, 10.0);
            double radiusY = randomInRange(1.0, 10.0);
            curves.push_back(std::make_shared<Ellipse>(radiusX, radiusY));
        } else if (type == 2) {
            double radius = randomInRange(1.0, 10.0);
            double step = randomInRange(1.0, 5.0);
            curves.push_back(std::make_shared<Helix>(radius, step));
        }
    }
}

int main() {
    std::vector<std::shared_ptr<Shape>> curves;

    // 2
    SeedVector(curves, 10);

    // 3
    double t = M_PI / 4;

    for (const auto &curve: curves) {
        Point point = curve->getPoint(t);
        Point derivative = curve->getDerivative(t);

        std::cout << "Point: (" << point.getX() << ", " << point.getY() << ", " << point.getZ() << ")\n";
        std::cout << "Derivative: (" << derivative.getX() << ", " << derivative.getY() << ", " << derivative.getZ()
                  << ")\n";
    }

    //4
    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto &curve: curves) {
        if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
            circles.push_back(circle);
        }
    }

    //5
    std::sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle> &a, const std::shared_ptr<Circle> &b) {
        return a->getRadius() < b->getRadius();
    });
    //6
    double totalRadiusSum = 0;
    for (const auto &circle: circles) {
        totalRadiusSum += circle->getRadius();
    }
    std::cout << "Total sum of radii of circles: " << totalRadiusSum << std::endl;

    return 0;
}