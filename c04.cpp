#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <cmath>

template <typename T>
int findMaxIndex(T arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

template <typename T, typename FunType>
std::vector<T> filter(const std::vector<T>& v, FunType p) {
    std::vector<T> res;
    for (T item : v) {
        if(p(item)) res.push_back(item);
    }
    return res;
}

template <typename T, typename FunType1, typename FunType2>
std::vector<T> transfilt(std::vector<T>& v, FunType1 t, FunType2 p) {
    for(int i = 0; i < v.size(); i++){
        v.at(i) = t(v.at(i));
    }
    return filter(v,p);
}

template <typename T>
void printVec(const std::vector<T>& v) {
    std::cout << "[ ";
    for (T it : v) {
        std::cout << it << ", ";
    }
    std::cout << "]\n";
}


int main() {

//=======================================================
//                        ZADANIE 1
    int arr1[] = {678, 12, 5, 215};
    double arr2[] = {3.14, 12.5, 34.7, 211.11};
    char arr3[] = {'a', 'f', 'e', 'b'};

    std::cout << "Max index of value: " << findMaxIndex(arr1, std::size(arr1)) << std::endl;
    std::cout << "Max index of value: " << findMaxIndex(arr2, std::size(arr1)) << std::endl;
    std::cout << "Max index of value: " << findMaxIndex(arr3, std::size(arr1)) << std::endl;
    std::cout << '\n';
//=======================================================
//                          ZADANIE 3
    std::vector<double> w{1.5, -3.1, 4.0, -2.0, 6.3};
    printVec(w);
    double mn = -0.5, mx = 0.5;
    std::vector<double> d = transfilt(w, [](double n) { return std::sin(n); },
                                 [mn, mx](double n) { return n >= mn && n <= mx; });
    printVec(w);
    printVec(d);
    std::cout << '\n';
//========================================================
//                          ZADANIE 2

    std::vector<int> v{ 1, -3, 4, -2, 6, -8, 5 };
    printVec(v);
    std::vector<int> r = filter(v, [](int x) { return x % 2 == 0; });
    printVec(r);
    std::vector<int> s = filter(v, [](int x) { return x > 0; });
    printVec(s);




    return 0;
}