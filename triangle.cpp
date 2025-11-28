//
// Created by nwaszkowiak on 26.11.24.
//

#include "triangle.h"
#include "point.h"
#include <cmath>

Triangle::Triangle(Point a, Point b, Point c) : a(a), b(b), c(c) {}

Triangle::Triangle(const Triangle &other) : a(other.a), b(other.b), c(other.c) {}

void Triangle::flip() {
    a.flip();
    b.flip();
    c.flip();
}

void Triangle::move(double x, double y) {
    a.move(x, y);
    b.move(x, y);
    c.move(x, y);
}

std::string Triangle::toString() {
    return "Triangle(" + a.toString() + ", " + b.toString() + ", " + c.toString() + ")";
}

double Triangle::getSurface() {
    double a = sqrt(pow(this->b.getX() - this->c.getX(), 2) + pow(this->b.getY() - this->c.getY(), 2));
    double b = sqrt(pow(this->a.getX() - this->c.getX(), 2) + pow(this->a.getY() - this->c.getY(), 2));
    double c = sqrt(pow(this->a.getX() - this->b.getX(), 2) + pow(this->a.getY() - this->b.getY(), 2));
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool Triangle::equals(Triangle &other) {
    return a.equals(other.a) && b.equals(other.b) && c.equals(other.c);
}
