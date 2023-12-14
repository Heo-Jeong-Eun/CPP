//
// Created by jeong on 2023-11-27.
//
#include <iostream>
#include "singleLinkedList/singleLinkedList.hpp"

int main() {
    singlyLinkedList sll = {1, 2, 3};
    sll.push_front(0);

    std::cout << "첫번째 리스트: ";
    for (auto it = sll.begin(); it != sll.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    auto sll2 = sll;
    sll2.push_front(-1);
    std::cout << "첫 번째 리스트를 복사한 후, 맨 앞에 -1을 추가: ";
    for (auto i: sll2)
        std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "DeepCopy 이후 첫번째 리스트는: ";
    for (auto i: sll)
        std::cout << i << " ";
    std::cout << std::endl;
}
