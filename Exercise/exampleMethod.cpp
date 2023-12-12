//
// Created by jeong on 2023-12-08.
//
#include <string>
#include <forward_list>
#include <iostream>

struct ID {
    int idx = 0;
    std::string name;

    ID(int number, std::string fname) {
        idx = number;
        name = fname;

        std::cout << "생성" << std::endl;
    }

    ID(const ID &that) : idx(that.idx), name(that.name) { std::cout << "copy object\n"; }
};

int main() {

//    std::cout << "std1 생성\n";
//    ID student1(1, "jeong");
//
//    std::cout << "std1를 가지고(복사) std2 생성\n";
//    ID student2(student1);
//
//    std::forward_list<ID> class1;
//
//    std::cout << "std를 class1에 push\n";
//    class1.push_front(student1);
//
//    std::cout << "정은이를 class1에 push\n";
//    class1.push_front(ID(2, "Heo"));
//
//    std::cout << "정은이를 class1에 push\n";
//    class1.emplace_front(3, "heo");


    std::forward_list<ID> class1;

    class1.push_front(ID(1, "A"));

    auto it = class1.begin();

    std::cout << it->name << std::endl;

    class1.emplace_front(2, "B");

    std::cout << it->name << std::endl;

    class1.push_front(ID(3, "C"));

    std::cout << it->name << std::endl;

    class1.pop_front();
    std::cout << it->name << std::endl;

    class1.emplace_front(2, "B");

    std::cout << it->name << std::endl;


    return 0;
}