#include <iostream>
#include <vector>
#include <cmath>

enum Banks {PKO,BGZ, BRE, BPH};

struct Account {
    Banks bank;
    int balance;
};

struct Person {
    char name[20];
    Account account;
};

struct Couple {
    Person he;
    Person she;
};

const Couple* bestClient(const Couple* cpls,
                         int size,
                         Banks bank) {

    const Couple* bestCouple = nullptr;
    int maxSavings = 0;

    for (int i = 0; i < size; i++) {
        const Couple& couple = cpls[i];

        if (couple.he.account.bank == bank || couple.she.account.bank) {
            int savings = couple.he.account.balance + couple.she.account.balance;

            if (savings > maxSavings) {
                bestCouple = &couple;
                maxSavings = savings;
            }
        }
    }
    return bestCouple;
}

struct Point {
    double x;
    double y;
};

struct Rect {
    Point upperLeft;
    Point lowerRight;
};

std::vector<double> process(const Rect* rects,
                            size_t sz,
                            std::function<double (Rect)> f) {

    std::vector<double> result(sz);

    for (size_t i = 0; i < sz; i++) {
        result[i] = f(rects[i]);
    }
    return result;
}

double area(Rect r) {
    double width = r.lowerRight.x - r.upperLeft.x;
    double height = r.upperLeft.y - r.lowerRight.y;

    return width * height;
}

double diagonal(Rect r) {
    double width = r.lowerRight.x - r.upperLeft.x;
    double height = r.upperLeft.y - r.lowerRight.y;

    return std::sqrt(width * width + height * height);
}


int main() {

    Rect rects[] = {
            {{0, 4}, {4, 1}
            },
            {{-6, 3}, {6, -2}
            },
            {{-7, 4}, {8, -4}
            }
    };
    size_t sz = std::size(rects);

    std::vector<double> areas = process(rects, sz, [](Rect r) { return area(r); });
    std::vector<double> diagonals = process(rects, sz, diagonal);

    std::cout << "ZADANIE 1: " << std::endl;
    for (size_t i = 0; i < sz; i++) {
        std::cout << "Prostokat " << i + 1 << " pole: "<< areas[i] << " przekatna: " << diagonals[i] << std::endl;
    }
    std::cout << "\n";

    Couple cpls[] = {
            {
                "Johny", PKO, 1200,
                "Marry", PKO, 1400
            },
            {
                "Peter", BGZ, 1400,
                "Suzy", BRE, -1500
            },
            {
                "Kevin", PKO, 1600,
                "Katy", BPH, 1500
            },
            {
                "Kenny", BPH, 200,
                "Lucy", BRE, -201
            }
    };


    const Couple* p = bestClient(cpls, std::size(cpls), BRE);

    std::cout << "ZADANIE 2: " << std::endl;
    if (p)
        std::cout << p -> he.name << " and " << p -> she.name
                  << ": " << p -> he.account.balance +
                             p -> she.account.balance << std::endl;
    else
        std::cout << "No such couple... \n";




    return 0;
}

