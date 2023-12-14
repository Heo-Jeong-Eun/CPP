//
// Created by jeong on 2023-11-25.
//
#include <iostream>
#include <forward_list>

using namespace std;

template<typename T>
void print(forward_list<T> &fwd) {
    for (auto n: fwd)
        cout << n << " ";
    cout << endl;
}

int main() {
    forward_list<int> fwd_list = {1, 2, 3};
//    fwd_list.push_front(0);
    auto it = fwd_list.begin();
    fwd_list.insert_after(it, 0);
    print(fwd_list);
    fwd_list.insert_after(it++, -1);
    print(fwd_list);
//    fwd_list.pop_front();
//    print(fwd_list);
////    cout << *it << endl;
//    it = fwd_list.begin();
    fwd_list.erase_after(it);
    print(fwd_list);
    fwd_list.erase_after(it, fwd_list.end());
    print(fwd_list);

}