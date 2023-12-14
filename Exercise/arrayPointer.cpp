//
// Created by jeong on 2023-11-26.
//
#include <iostream>

int main() {
    int *arr;
    arr = new int[3];

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    std::cout << "arr[0]" << arr[0] << " " << *arr << std::endl;
    std::cout << "arr[1]" << arr[1] << " " << *(arr + 1) << std::endl;
    std::cout << "arr[2]" << arr[2] << " " << *(arr + 2) << std::endl;
    return 0;
}