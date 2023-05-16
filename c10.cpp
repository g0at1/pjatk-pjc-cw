#include <iostream>
#include "Segment.h"

Segment::Segment(double A, double B) : A(A), B(B) {}

Segment Segment::operator*(double d) const {
    return Segment(d * A, d * B);
}

Segment Segment::operator/(double d) const {
    return Segment(A / d, B / d);
}

Segment Segment::operator+(double d) const {
    return Segment(A + d, B + d);
}

Segment Segment::operator-(double d) const {
    return Segment(A - d, B - d);
}

Segment Segment::operator+(const Segment& other) const {
    double newA = std::min(A, other.A);
    double newB = std::max(B, other.B);
    return Segment(newA, newB);
}

bool Segment::operator()(double d) const {
    return d >= A && d <= B;
}

std::ostream& operator<<(std::ostream& os, const Segment& seg) {
    os << "[" << seg.A << "," << seg.B << "]";
    return os;
}

Segment operator*(double d, const Segment& seg) {
    return seg * d;
}

Segment operator+(double d, const Segment& seg) {
    return seg + d;
}


int main() {

    Segment seg{2,3}, s = 1 + 2*((seg-2)/2+seg)/3;
    std::cout << s << std::endl << std::boolalpha;
    for (double x = 0.5; x < 4; x += 1)
        std::cout << "x=" << x << ": " << s(x) << std::endl;


    return 0;
}