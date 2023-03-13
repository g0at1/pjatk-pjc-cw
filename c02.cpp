#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

#define GETMAX
#define GETMIN

#define bok 16

void zadanie1();
void zadanie2();
double polePowierzchniGraniastoslupaPieciokatnego(double wysokosc);

int main() {

    //zadanie1();
    zadanie2();


    return 0;
}

void zadanie1() {
    std::cout << "Nazwa pliku zrodlowego: " << __FILE__ << std::endl;
    std::cout << "Data kompilacji: " << __DATE__ << std::endl;
    std::cout << "Godzina kompilacji: " << __TIME__ << std::endl;
}

void zadanie2() {
    std::vector<int> a;

    srand(time(NULL));

    for (int i = 0; i < 5; i++) {
        a.push_back((std::rand() % 100) + 1);
        std::cout << a.at(i) << " ";
    }

    int max = a.at(0), min = a.at(0);

    for (int i = 1; i < a.size(); i++) {
        if (max < a.at(i)) {
            max = a.at(i);
        }
        if (min > a.at(i)) {
            min = a.at(i);
        }
    }
    std::cout << std::endl;

#if defined(GETMAX) && defined(GETMIN)
    std::cout << "Max value: " << max << std::endl;
    std::cout << "Min value: " << min << std::endl;
#elif defined(GETMAX)
    std::cout << "MAX: " << max;
#elif defined(GETMIN)
    std::cout<< "MIN: " << min;
#else
#error
#endif

}

double poleKwadratu() {
    return bok * bok;
}

double polePowierzchniGraniastoslupaPieciokatnego(double wysokosc) {
    double podstawa = (5.0 / 4.0) * bok * bok * tan(M_PI / 5.0);
    double bbok = bok * wysokosc;
    double powierzchnia_boczna = 5 * bbok;
    return podstawa*2 + powierzchnia_boczna;
}





