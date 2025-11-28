//
// Created by nwaszkowiak on 26.11.24.
//

#include "group.h"
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "quadrilateral.h"

Group::Group() {}

Group::Group(const Group &other): lines(other.lines), triangles(other.triangles), quadrilaterals(other.quadrilaterals) {}

void Group::remove(Line line) {
    int index = -1;
    for (std::vector<Line>::size_type i = 0; i < lines.size(); ++i) {
        if (lines[i].equals(line)) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        lines.erase(lines.begin() + index);
    }
}

void Group::remove(Triangle triangle) {
    int index = -1;
    for (std::vector<Line>::size_type i = 0; i < triangles.size(); ++i) {
        if (triangles[i].equals(triangle)) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        triangles.erase(triangles.begin() + index);
    }
}

void Group::remove(Quadrilateral quadrilateral) {
    int index = -1;
    for (std::vector<Line>::size_type i = 0; i < quadrilaterals.size(); ++i) {
        if (quadrilaterals[i].equals(quadrilateral)) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        quadrilaterals.erase(quadrilaterals.begin() + index);
    }
}

void Group::add(Line line) {
    lines.push_back(line);
}

void Group::add(Triangle triangle) {
    triangles.push_back(triangle);
}

void Group::add(Quadrilateral quadrilateral) {
    quadrilaterals.push_back(quadrilateral);
}

void Group::flip() {
    for (auto &line : lines) {
        line.flip();
    }
    for (auto &triangle : triangles) {
        triangle.flip();
    }
    for (auto &quadrilateral : quadrilaterals) {
        quadrilateral.flip();
    }
}

void Group::move(double x, double y) {
    for (auto &line : lines) {
        line.move(x, y);
    }
    for (auto &triangle : triangles) {
        triangle.move(x, y);
    }
    for (auto &quadrilateral : quadrilaterals) {
        quadrilateral.move(x, y);
    }
}

std::string Group::toString() {
    std::string result = "Group(";
    for (auto &line : lines) {
        result += line.toString() + ", ";
    }
    for (auto &triangle : triangles) {
        result += triangle.toString() + ", ";
    }
    for (auto &quadrilateral : quadrilaterals) {
        result += quadrilateral.toString() + ", ";
    }
    result += ")";
    return result;
}

double Group::getSurface() {
    double result = 0;
    for (auto &triangle : triangles) {
        result += triangle.getSurface();
    }
    for (auto &quadrilateral : quadrilaterals) {
        result += quadrilateral.getSurface();
    }
    return result;
}

bool Group::equals(Group &other) {
    for (std::vector<Line>::size_type i = 0; i < lines.size(); ++i) {
        if (!lines[i].equals(other.lines[i])) {
            return false;
        }
    }
    for (std::vector<Line>::size_type i = 0; i < triangles.size(); ++i) {
        if (!triangles[i].equals(other.triangles[i])) {
            return false;
        }
    }
    for (std::vector<Line>::size_type i = 0; i < quadrilaterals.size(); ++i) {
        if (!quadrilaterals[i].equals(other.quadrilaterals[i])) {
            return false;
        }
    }
    return true;
}


