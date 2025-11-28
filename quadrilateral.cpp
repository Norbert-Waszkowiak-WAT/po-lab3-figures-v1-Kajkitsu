//
// Created by nwaszkowiak on 26.11.24.
//
#include <cmath>

#include "quadrilateral.h"
#include "point.h"

Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d) : a(a), b(b), c(c), d(d) {}

Quadrilateral::Quadrilateral(const Quadrilateral &other) : a(other.a), b(other.b), c(other.c), d(other.d) {}

void Quadrilateral::flip() {
    a.flip();
    b.flip();
    c.flip();
    d.flip();
}

void Quadrilateral::move(double x, double y) {
    a.move(x, y);
    b.move(x, y);
    c.move(x, y);
    d.move(x, y);
}

std::string Quadrilateral::toString() {
    return "Quadrilateral(" + a.toString() + ", " + b.toString() + ", " + c.toString() + ", " + d.toString() + ")";
}

double Quadrilateral::getSurface() {
    double x1 = a.getX(), y1 = a.getY();
    double x2 = b.getX(), y2 = b.getY();
    double x3 = c.getX(), y3 = c.getY();
    double x4 = d.getX(), y4 = d.getY();

    // Shoelace formula for quadrilateral
    double area = 0.5 * fabs(x1*y2 + x2*y3 + x3*y4 + x4*y1 - y1*x2 - y2*x3 - y3*x4 - y4*x1);
    return area;
}

bool Quadrilateral::equals(Quadrilateral &other) {
    return a.equals(other.a) && b.equals(other.b) && c.equals(other.c) && d.equals(other.d);
}
