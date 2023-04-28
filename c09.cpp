#include <iostream>
#include <string>
#include "c09.h"

Resistor::Resistor() {
    R = 0;
}

Resistor::Resistor(double r) {
    R = r;
}

void Resistor::r(double r) {
    R = r;
}

double Resistor::r() const {
    return R;
}

std::ostream &operator<<(std::ostream& str, const Resistor& r1) {
    return str << "Opor rezystora wynosi: " << r1.r();
}

Resistor operator+(const Resistor& r1, const Resistor& r2) {
    return {r1.r() + r2.r()};
}

Resistor operator*(const Resistor& r1, const Resistor& r2) {
    return (r1.r() * r2.r()) / (r1.r() + r2.r());
}


int main() {
    //ZADANIE 1
    MyStack<std::string> stS;
    MyStack<double> stD;
    for (int i = 5; i > 0; --i) {
        stS.push(std::to_string(double(i)));
        stD.push(double(i));
    }
    while (!stS.isEmpty())
        std::cout << "string: " << stS.pop() << " "<< "double: " << stD.pop() << std::endl;

    //ZADANIE 2
    Resistor r1, r2{6};
    r1.r(3);
    std::cout << (r1 + r2) << " " << (r1 * r2) << std::endl;


    return 0;
}