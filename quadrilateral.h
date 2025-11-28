//
// Created by nwaszkowiak on 26.11.24.
//

#ifndef PO_LAB3_FIGURES_QUADRILATERAL_H
#define PO_LAB3_FIGURES_QUADRILATERAL_H

#include "point.h"

class Quadrilateral {
private:
    Point a;
    Point b;
    Point c;
    Point d;

    double calculateAngle(Point p1, Point p2, Point p3);

    double calculateTheta(Point a, Point b, Point c, Point d);

public:
    Quadrilateral(Point a, Point b, Point c, Point d);

    Quadrilateral(const Quadrilateral &other);

    bool equals(Quadrilateral &other);

    void flip();

    void move(double x, double y);

    std::string toString();

    double getSurface();

};


#endif //PO_LAB3_FIGURES_QUADRILATERAL_H
