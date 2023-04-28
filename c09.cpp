#include <iostream>
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

Person::Person(std::string name) : name(name), id(ID++) {}

void Person::makeFriends(Person& p) {
    for (auto const& friendPtr : friends) {
        if (friendPtr == &p)
            return;
    }

    friends.push_back(&p);
    p.friends.push_back(this);
}

void Person::listOfFriends() const {
    std::cout << name << "'s friends -> ";
    for (const Person* p : friends)
        std::cout << p->name << "(" << p->id << ") ";
    std::cout << std::endl;
}

std::vector<const Person*> Person::friendsOfFriends() const {
    std::vector<const Person*> fof;
    for (const Person* p : friends) {
        for (const Person* f : p->friends) {
            if (std::find(friends.begin(), friends.end(), f) == friends.end() && f != this)
                fof.push_back(f);
        }
    }
    return fof;
}

std::string Person::info() const {
    return name + "(" + std::to_string(id) + ")";
}

size_t Person::ID{1};


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

    //ZADANIE 3
    Person john{"John"}, mary{"Mary"}, kitty{"Kitty"},
            jill{"Jill"}, bob{"Bob"}, eve{"Eve"};

    john.makeFriends(mary); john.makeFriends(bob);
    john.makeFriends(eve); bob.makeFriends(john);
    bob.makeFriends(jill); bob.makeFriends(eve);
    eve.makeFriends(mary); eve.makeFriends(kitty);
    john.listOfFriends();

    std::cout << "Friends of John's friends -> ";
    for (const Person* p : john.friendsOfFriends())
        std::cout << p->info() << " ";
    std::cout << std::endl;


    return 0;
}