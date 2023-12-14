//
// Created by jeong on 2023-12-07.
//
#include<iostream>
#include "circularLinkedList/circularLinkedList.hpp"


int main() {

    circularLinkedList playList(2);
    playList.push_front(1);

    std::cout << "push_front test: ";
    print(playList);

    playList.push_back(3);
    std::cout << "push_back test : ";
    print(playList);

    playList.insert(playList.begin(), 0, 6);
    print(playList);

    playList.erase(2);
    print(playList);

    playList.erase(6);
    print(playList);
    playList.pop_front();
    print(playList);

    playList.pop_back();
    print(playList);

}
