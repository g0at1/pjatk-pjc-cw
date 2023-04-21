#include <iostream>
#include <vector>

struct Animal {
    virtual void makeSound() = 0;
};

struct Dog : Animal {
    void makeSound() override {
        std::cout << "Bark" << std::endl;
    }
};

struct Cat : Animal {
    void makeSound() override {
        std::cout << "Meow" << std::endl;
    }
};

struct Bird : Animal {
    void makeSound() override {
        std::cout << "Bird sound" << std::endl;
    }
};

struct Fish : Animal {
    void makeSound() override {
        std::cout << "Fish sound" << std::endl;
    }
};


int main() {

    std::vector<Animal*> animals = {
        new Dog(),
        new Cat(),
        new Bird(),
        new Fish()
    };

    for (auto animal : animals) {
        animal->makeSound();
        delete animal;
    }

    return 0;
}