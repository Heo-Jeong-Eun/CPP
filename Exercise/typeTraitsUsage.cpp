//
// Created by jeong on 2023-11-25.
//
#include <iostream>
#include <type_traits>

template<class T>
using add_const_t = typename std::add_const<T>::type;

struct foo {
    void m() { std::cout << "Non-CV \n"; }

    void m() const { std::cout << "Const \n"; }

    void m() volatile { std::cout << "Volatile \n"; }

    void m() const volatile { std::cout << "Const Volatile \n"; }
};

int main()
{
    foo{}.m();
    std::add_const<foo>::type{}.m();
    std::add_volatile<foo>::type{}.m();
    std::add_cv<foo>::type{}.m();
}