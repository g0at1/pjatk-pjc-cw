#include <iostream>
#include <string>
#include <vector>

// ZADANIE: FILTROWANIE IMION
// http://users.pja.edu.pl/~fk/posts/Zadanie-filtrowanie-imion/
std::vector<std::string> getNamesFrom(const std::vector<std::string> &v) {
    std::vector<std::string> result;
    for (const auto& str : v) {
        if (std::isupper(str[0])) {
            result.push_back(str);
        }
    }
    return result;
}


// ZADANIE: GENERYCZNE SUMOWANIE
// http://users.pja.edu.pl/~fk/posts/Zadanie-generyczne-sumowanie/
template <typename T>
T sum(const std::vector<T> &v) {
    T result{};
    for (const auto& element : v) {
        result += element;
    }
    return result;
}

// ZADANIE: GENERYCZNA PĘTLA
// http://users.pja.edu.pl/~fk/posts/Zadanie-generyczna-petla/
template <typename Fun>
void repeat(int n, Fun f) {
    for (int i = 0; i < n; i++) {
        f();
    }
}

int main() {

    // ZADANIE: FILTROWANIE IMION
    std::vector<std::string> input {"adam", "Anastasia", "ewa", "Illia", "Maciej", "natalia"};
    std::vector<std::string> output = getNamesFrom(input);

    std::cout << "Filtered names: ";
    for (const auto& str : output) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::cout << "\n";

    // ZADANIE: GENERYCZNE SUMOWANIE
    std::vector<int> v = {13, 55, 123, 6, 5};
    int result = sum(v);
    std::cout << "Sum of vector elements: " << result << std::endl;

    std::cout << "\n";

    // ZADANIE: GENERYCZNA PĘTLA
    repeat(5, []() -> void {
        std::cout << "Hello, world!" << std::endl;
    });

    return 0;
}