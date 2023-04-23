#include <iostream>
#include <cmath>
#include "c08.h"

class Point {
    double x, y;

public:
    Point();
    Point(double s);
    Point(double x, double y);

    double getX() const;
    double getY() const;
    Point& setX(double xx);
    Point& setY(double yy);
    Point& transX(double dx);
    Point& transY(double dy);
    Point& transXY(double dx, double dy);
    static double dist(const Point& p, const Point& q);
};

class Rect {
    double a, b;

public:
    Rect(): a(1), b(1) {};
    Rect(double s): a(s), b(s) {};
    Rect(double a, double b): a(a), b(b) {};

    double getA() const {
        return a;
    }

    double getB() const {
        return b;
    }

    double getDiagonal() const {
        return std::sqrt(a * a + b * b);
    }

    double getArea() const {
        return a * a;
    }

    bool isLargerThan(const Rect& other) const {
        return getArea() > other.getArea();
    }

    void info() const {
        std::cout << "Rect[" << getA() << "," << getB() << "]" << std::endl;
    }
};

Point::Point() {
    x = 0;
    y = 0;
}

Point::Point(double s) {
    x = s;
    y = s;
}

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

Point &Point::setX(double xx) {
    x = xx;
    return *this;
}

Point &Point::setY(double yy) {
    y = yy;
    return *this;
}

Point &Point::transX(double dx) {
    x += dx;
    return *this;
}

Point &Point::transY(double dy) {
    y += dy;
    return *this;
}

Point &Point::transXY(double dx, double dy) {
    x += dx;
    y += dy;
    return *this;
}

double Point::dist(const Point &p, const Point &q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;

    return std::sqrt(dx * dx + dy * dy);
}


int main() {
    Point p;
    Point q(1);
    Point r(1, 2);
    p.transXY(5, 6);
    q.transX(-1).transY(-1).transXY(2, 2);
    r.setX(10).transY(-8);
    std::cout << Point::dist(p, q) << std::endl;
    std::cout << Point::dist(p, r) << std::endl;

    Rect rect;
    Rect rect2(2);
    Rect rect3(2, 3);

    std::cout << rect3.isLargerThan(rect2) << std::endl;
    std::cout << rect2.getDiagonal() << std::endl;
    rect.info();

    return 0;
}