#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <fmt/ranges.h>
#include <algorithm>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::rand;

auto isEven(int n) -> bool {
    return n % 2 == 0;
}

int main() {
    std::vector<int> vec1 = {1, 2, 3, 2, 3, 4, 2, 3, 4, 1, 3, 4, 2, 2, 3, 4, 2, 3, 4, 1, 2, 3, 4, 4, 5, 6};
    fmt::print("{}\n", vec1);
    fmt::print("żółw\n");
    vec1.insert(vec1.begin() + 3, 4);
    fmt::print("{}\n", vec1);
    vec1.erase(vec1.begin() + 3, vec1.begin() + 5);
    vec1.erase(vec1.begin(), vec1.end());
    fmt::print("{}\n", vec1);

    //zlicznie
    std::vector<int> vec2 = {1, 2, 3, 2, 3, 4, 2, 3, 4, 1, 3, 4, 2, 2, 3, 4, 2, 3, 4, 1, 2, 3, 4, 4, 5, 6};
    auto cout2 = std::count(vec2.begin(), vec2.end(), 2);
    auto cout2_1 = std::count(vec2.begin(), vec2.end(), 2);
    fmt::print("{}\n", cout2);
    fmt::print("{}\n", cout2_1);

    //sortowanie
    std::sort(vec2.begin(), vec2.end());
    fmt::print("{}\n", vec2);

    //zlicznie ile elementow parzystych
    auto countEven=std::count_if(vec2.begin(),vec2.end(), isEven);
    fmt::print("{}\n", vec2);

    //lambda
    auto isEven2=[](int n) -> bool {
        return n % 2 == 0;
    };

    auto countEven2=std::count_if(vec2.begin(),vec2.end(), isEven2);

    auto countEven3=std::count_if(vec2.begin(),vec2.end(),[](int n) -> bool {
        return n % 2 == 0;
    } );

    /*auto isEven(int n) -> bool {
        return n % 2 == 0;
    }*/


    //W tym pliku przedstawiam Państwu podstawowe przykłady wpisywania wartości do plików, jak i odczytywanie ich
    //Po więcej informacji zalecam spojrzeć do wykładów (rozdział 16, ze szczególną uwagą na podroździał 16.5)
    // link - https://edu.pjwstk.edu.pl/wyklady/pro/scb/PRG2CPP_files/node106.html

    //write
    std::fstream fileOut;
    fileOut.open("plik.txt",std::ios::out ); //pierwszym argumentem jest ścieżka do pliku, a drugim są flagi. Ta flaga pozwana nam wpisywać wiersze do pliku
    if(fileOut.is_open()){ //sprawdzam czy plik zostal poprawnie otwarty
        fileOut<<"Hello\n";
        fileOut<<"World\n";
        fileOut.close();//Należy pamięać o zamknięciu strumieni
    }
    /* W pliku
    Hello
    World
     */

    fileOut.open("plik.txt",std::ios::out);//plik zostanie wyczyszczony i zostaną dodane do niego nowe wartości
    if(fileOut.is_open()){
        fileOut<<"Hello2\n";
        fileOut.close();
    }
    /* W pliku
    Hello2
     */

    fileOut.open("plik.txt",std::ios::app);//append - wyrazy zostaną dodane do pliku (bez usuwania istniejących wartości)
    if(fileOut.is_open()){
        fileOut<<"World2\n";
        fileOut.close();
    }
    /* W pliku
    Hello2
    World2
     */

    //read
    std::fstream fileIn;
    fileIn.open("plik.txt",std::ios::in);//umożliwia odczyt z pliku
    if(fileIn.is_open()){
        //pobranie pojedynczego słowa można zrealizować za pomocą operatora <<
        //std::string word;
        //fileIn >> word;
        std::string line;
        while (std::getline(fileIn,line)){
            std::cout<<line<<std::endl;
        }
        fileIn.close();
    }


    //Można korzystać jednocześnie z więcej niż jednego trybu
    //np. obiekt strumienia (klasy fstream) w trybie do zapisu i odczytu.
    //łączymy je za pomocą alternetywy bitowej |
    std::fstream strum("plik.txt", std::ios::in | std::ios::out);//w jednej linijce utworzenie obiektu i związanie go z konkretnym plikiem
    strum.close();


    //Występuje więcej rodzajów trybów - te podane na wykładzie
    /*
     ios::in — zezwala na odczyt ze strumienia;
     ios::out — zezwala na zapis do strumienia;
     ios::trunc — (truncate) po utworzeniu usuń dotychczasową zawartoś";
     ios::ate — po otwarciu ustaw na końcu pliku (at end);
     ios::app — (append) przechodź na koniec strumienia dla każdej operacji wstawiania (pisania);
     ios::binary — nie interpretuj w żaden sposób znaków końca linii i powrotu karetki (w Linuksie ta opcja jest zbędna, ale przydaje się w Windows, gdzie koniec linii oznaczany jest za pomocą dwóch znaków);
     */

    return 0;
}
