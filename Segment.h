#ifndef PJC_CLION_SEGMENT_H
#define PJC_CLION_SEGMENT_H

#include <iostream>


class Segment {
    double A, B;
public:
    Segment(double A, double B);

    Segment operator*(double d) const;
    Segment operator/(double d) const;
    Segment operator+(double d) const;
    Segment operator-(double d) const;
    Segment operator+(const Segment& other) const;
    bool operator()(double d) const;
    friend std::ostream& operator<<(std::ostream& os, const Segment& seg);
    friend Segment operator*(double d, const Segment& seg);
    friend Segment operator+(double d, const Segment& seg);
};

#endif //PJC_CLION_SEGMENT_H
