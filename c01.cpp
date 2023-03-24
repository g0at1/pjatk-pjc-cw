#include <iostream>
#include <cmath>

void zadanie1();
void zadanie2();
void zadanie3();

int main() {

    //zadanie1();
    //zadanie2();
    zadanie3();

    return 0;
}


void zadanie1() {
    double wzrost, waga;

    std::cout << "Podaj wzrost: ";
    std::cin >> wzrost;

    std::cout << "Podaj wage: ";
    std::cin >> waga;

    double BMI = waga / (pow(wzrost, 2)) * 10000;

    std::cout << "Twoje BMI: " << BMI;
}

void zadanie2() {
    int i = 0;
    int l1; int l2; int l3;

    std::cout << "Enter three non-negative numbers: ";
    std::cin >> l1 >> l2 >> l3;

    int wiersz = l1;

    if (l1 > l2) {
        if (l1 > l3)
            wiersz = l1;
        else
            wiersz = l3;
    }
    else {
        if (l2 > l3)
            wiersz = l2;
        else
            wiersz = l3;
    }
    while (i < l1 + l2 + l3) {
        if (l1 >= wiersz) {
            std::cout << "*";
            i++;
        }
        else
            std::cout << " ";

        if (l2 >= wiersz) {
            std::cout << "*";
            i++;
        }
        else
            std::cout << " ";

        if (l3 >= wiersz) {
            std::cout << "*" << std::endl;
            i++;
        }
        else
            std::cout << " " << std::endl;

        wiersz -= 1;
    }
}

void zadanie3() {
    int maxSum = 0;
    int maxNum = 0;
    int num = 9;

    while (num != 0) {
        std::cout << "Enter a natural number (0 if done): ";
        std::cin >> num;

        int sumDigits = 0;
        int tmp = num;
        while (tmp > 0) {
            sumDigits += tmp % 10;
            tmp /= 10;
        }
        if (sumDigits > maxSum) {
            maxSum = sumDigits;
            maxNum = num;
        }
    }
    std::cout << "Max sum of digits was "
              << maxSum << " for " << maxNum << std::endl;
}