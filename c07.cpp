#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <filesystem>

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

void zadanie2();
int zadanie3();


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
    std::cout << '\n';

    //zadanie2();
    //zadanie3();

    return 0;
}

void zadanie2() {
    std::string dirPath;
    std::cin >> dirPath;
    auto dirIter = std::filesystem::recursive_directory_iterator(dirPath);
    auto counter = std::map<std::string, int>();
    for (auto const &entry: dirIter)
        if (entry.is_regular_file()) {
            std::fstream fstr(entry.path());
            if (fstr.is_open()) {
                std::string str;
                while (fstr >> str) {
                    counter[str]++;
                }
            }
            fstr.close();
        }
    std::string maxStr = "";
    auto maxStrIle = 0;
    for (auto [word, count]: counter) {
        if (count > maxStrIle) {
            maxStrIle = count;
            maxStr = word;
        }
    }
    std::cout << maxStrIle << std::endl;
    std::cout << maxStr;
}

int zadanie3() {
    std::string path;
    std::cin >> path;
    std::fstream file(path);
    if (!file.is_open()) {
        std::cout << "Error" << std::endl;
        return 1;
    }
    std::vector<std::string> words;
    std::map<int, int> number_counts;
    std::string word;
    while (file >> word) {
        std::string clean_word ="";
        for (char c : word) {
            if (isdigit(c)) {
                clean_word += c;
            }
        }
        if (!clean_word.empty()) {
            int number = stoi(clean_word);
            words.push_back(word);
            number_counts[number]++;
        }
        else {
            words.push_back(word);
        }
    }
    int most_common_number = 0;
    int max_count = 0;
    for (const auto& pair : number_counts) {
        if (pair.second > max_count) {
            most_common_number = pair.first;
            max_count = pair.second;
        }
    }
    std::cout << "Liczba slow: " << words.size() << std::endl;
    std::cout << "Liczba liczb: "
              << number_counts.size() << " najczesciej wystepujaca "
              << most_common_number << " i wystepuje " << max_count << std::endl;

    return 0;
}