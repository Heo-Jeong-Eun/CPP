//
// Created by jeong on 2023-11-25.
//
#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void print(const std::vector<T> &arr) {
    for (auto n: arr)
        std::cout << n << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    vec.push_back(6);
    vec.push_back(6);

    vec[2] = -1;
    print(vec);

    vec.insert(vec.begin(), 0);
    print(vec);
}