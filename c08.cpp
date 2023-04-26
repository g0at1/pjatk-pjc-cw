#include <iostream>
#include <cmath>
#include "c08.h"

//ZADANIE 1
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

//ZADANIE 2
Rect::Rect(): a(1), b(1) {};
Rect::Rect(double s): a(s), b(s) {};
Rect::Rect(double a, double b): a(a), b(b) {};

double Rect::getA() const {
    return a;
}

double Rect::getB() const {
    return b;
}

double Rect::getDiagonal() const {
    return std::sqrt(a * a + b * b);
}

double Rect::getArea() const {
    return a * a;
}

bool Rect::isLargerThan(const Rect& other) const {
    return getArea() > other.getArea();
}

void Rect::info() const {
    std::cout << "Rect[" << getA() << "," << getB() << "]" << std::endl;
}


int main() {
    //ZADANIE 1
    Point p;
    Point q(1);
    Point r(1, 2);
    p.transXY(5, 6);
    q.transX(-1).transY(-1).transXY(2, 2);
    r.setX(10).transY(-8);
    std::cout << Point::dist(p, q) << std::endl;
    std::cout << Point::dist(p, r) << std::endl;

    //ZADANIE 2
    Rect rect;
    Rect rect2(2);
    Rect rect3(2, 3);

    std::cout << rect3.isLargerThan(rect2) << std::endl;
    std::cout << rect2.getDiagonal() << std::endl;
    rect.info();

    return 0;
}