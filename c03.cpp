#include <iostream>
#include <vector>
#include <algorithm>

bool sumOfTwo(std::vector<int>, int val);
void zadanie3();
void calc(std::vector<double>& v);

int main() {
    std::cout << "Exercise 1: " << std::endl;
    std::vector<int> v1 = {2, 4, 5, 8, 9, 11, 13, 15};
    int val = 21;
    sumOfTwo(v1, val);
    std:: cout << '\n';

    std::cout << "Exercise 3: " << std::endl;
    zadanie3();
    std::cout << '\n';

    std::vector<double> v2;
    double input;

    std::cout << "Insert 10 numbers: " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cin >> input;
        v2.insert(v2.begin(), input);
    }
    calc(v2);

    return 0;
}

bool sumOfTwo(std::vector<int> v, int val) {
    bool znalezione = false;
    int suma = 0;
    int p = 0;
    int end = v.size()-1;

    std::sort(v.begin(), v.end() - 1); //{0,2,3,3,5,6,8,8}

    while(!znalezione || (p > v.size() -1) || (end < 0)) {
        suma = v.at(p) + v.at(end);
        if(suma == val) {
            std::cout << p << "\n" << end << std::endl;
            znalezione = true;
        }
        else {
            if((suma < val)) {
                p += 1;
            }
            else {
                end -= 1;
            }
        }
    }
    return znalezione;
}

void zadanie3() {
    std::vector<int> vec = {10, 11, 213, 12, 10, 123};

    auto is10 = [](int n) -> bool { return n == 10; };
    auto counter=std::count_if(vec.begin(),vec.end(),is10);
    std::cout << "Number 10 count: " << counter << std::endl;

    auto isEven = [](int n) -> bool { return n % 2 != 0; };
    auto counterEven = std::count_if(vec.begin(), vec.end(), isEven);
    std::cout << "Even number count: " << counterEven << std::endl;

    auto isPrime = [](int n) -> bool {
        if (n == 1) {
            return false;
        }
        for (int i = 2; i < sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    };
    auto counterPrime = std::count_if(vec.begin(), vec.end(), isPrime);
    std::cout << "Prime number count: " << counterPrime << std::endl;
}

void calc(std::vector<double>& v) {
    static int counter = 0;

    if (counter % 2 == 0) {
        v[0] += v.back();
    } else {
        v[0] -= v.back();
    }
    v.pop_back();

    counter++;
    std::cout << "Vector: ";
    for (double element : v) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    if (v.size() > 1) {
        calc(v);
    }
}