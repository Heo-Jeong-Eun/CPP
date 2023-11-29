//
// Created by jeong on 2023-11-27.
//
#include "singleLinkedList.hpp"

void singlyLinkedList::push_front(int value) {
    auto newNode = new node{value, nullptr};
    if (head != nullptr) {
        newNode->next = head;
    }
    head = newNode;
}

void singlyLinkedList::pop_front() {
    auto first = head;
    if (head) {
        head = head->next;
        delete first;
    }
}

singlyLinkedList::singlyLinkedList(const singlyLinkedList &other) : head(nullptr) {
    head = new node{0, nullptr};
    auto cur = head;
    auto it = other.begin();
    while (true) {
        cur->data = *it;

        auto tmp = it;
        ++tmp;
        if (tmp == other.end())
            break;

        cur->next = new node{0, nullptr};
        cur = cur->next;
        it = tmp;
    }
}

singlyLinkedList::singlyLinkedList(const std::initializer_list<int> &ilist) : head(nullptr) {
    for(auto it = std::rbegin(ilist); it!=std::rend(ilist); it++){
        push_front(*it);
    }

}

singlyLinkedList::singlyLinkedListIterator &singlyLinkedList::singlyLinkedListIterator::operator++() {
    ptr = ptr->next;
    return *this;
}

singlyLinkedList::singlyLinkedListIterator singlyLinkedList::singlyLinkedListIterator::operator++(int) {
    singlyLinkedList::singlyLinkedListIterator result = *this;
    ++(*this);
    return result;
}
