#ifndef PJC_CLION_C08_H
#define PJC_CLION_C08_H

#include <iostream>
#include <cmath>
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
    Rect();
    Rect(double s);
    Rect(double a, double b);
    double getA() const;
    double getB() const;
    double getDiagonal() const;
    double getArea() const;
    bool isLargerThan(const Rect& other) const;
    void info() const;
};


#endif //PJC_CLION_C08_H


