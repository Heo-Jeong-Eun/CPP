//
// Created by jeong on 2023-11-27.
//
#include "circularLinkedList.hpp"
#include <iostream>

void print(const circularLinkedList &list) {

    if (list.begin().get() == nullptr && list.end().get() == nullptr){
        std::cout<<"empty list" << std::endl;
        return;
    }

    auto it = list.begin();
    do {
        std::cout << *it << " ";
        ++it;
    } while (it != list.end());
    std::cout << *it << " ";
    std::cout << std::endl;
}

circularLinkedList::circularLinkedList(const int &newData) : front(nullptr), back(nullptr) {
    nodePtr newNode = new node{newData, nullptr, nullptr};
    if (front == nullptr) {
        front = newNode;
        back = newNode;
        front->next = front;
        front->prev = front;
    }

}

void circularLinkedList::insert(circularLinkedList::circularLinkedListIterator pos, int step, int value) {

    auto newNode = new node{value, nullptr, nullptr};
    if (step > 0) {
        while (step > 0) {
            pos++;
            step--;
        }
    } else if (step < 0) {
        while (step < 0) {
            pos--;
            step++;
        }
    }
    if (pos == begin()) {
        push_front(value);
        return;
    }
    if (pos == end()) {
        push_back(value);
        return;
    }
    auto cur = pos.get();
    auto temp = cur;
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    newNode->next = cur;
    cur->prev = newNode;
}

void circularLinkedList::erase(int value) {

    nodePtr item = nullptr;
    for (auto it = this->begin(); it != this->end(); it++) {
        if (*it == value) {
            item = it.get();
            break;
        }
    }
    if (item == nullptr) {
        if (*(this->end()) == value) {
            item = this->end().get();
        } else {
            return;
        }
    }

    if (item == front) {
        pop_front();
        return;
    }
    if (item == back) {
        pop_back();
        return;
    }
    auto temp = item;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete item;
}

void circularLinkedList::push_front(int value) {
    auto newNode = new node{value, nullptr, nullptr};
    if (front == nullptr) {
        front = newNode;
        back = newNode;
        front->next = front;
        front->prev = front;
    } else {
        newNode->next = front;
        front->prev = newNode;
        newNode->prev = back;
        front = newNode;
    }
}

void circularLinkedList::pop_front() {
    auto first = front;
    if (front) {
        front = front->next;
        if (first == front) {
            back = nullptr;
            front = nullptr;
        } else {
            front->prev = back;
            back->next = front;
        }
        delete first;
    }
}

void circularLinkedList::push_back(int value) {
    auto newNode = new node{value, nullptr, nullptr};
    if (back != nullptr) {
        back->next = newNode;
        newNode->prev = back;
        newNode->next = front;
        back = newNode;
    } else {
        back = newNode;
        front = newNode;
        back->prev = front;
        back->next = front;
        front->next = back;
        front->prev = back;
    }
}

void circularLinkedList::pop_back() {
    auto last = back;
    if (back) {
        back = back->prev;
        if (back == last) {
            front = nullptr;
            back = nullptr;
        } else {
            back->next = front;
            front->prev = back;
        }
        delete last;
    }
}


circularLinkedList::circularLinkedListIterator &circularLinkedList::circularLinkedListIterator::operator++() {
    ptr = ptr->next;
    return *this;
}

circularLinkedList::circularLinkedListIterator circularLinkedList::circularLinkedListIterator::operator++(int) {
    circularLinkedList::circularLinkedListIterator result = *this;
    ++(*this);
    return result;
}

circularLinkedList::circularLinkedListIterator &circularLinkedList::circularLinkedListIterator::operator--() {
    ptr = ptr->prev;
    return *this;
}

circularLinkedList::circularLinkedListIterator circularLinkedList::circularLinkedListIterator::operator--(int) {
    circularLinkedList::circularLinkedListIterator result = *this;
    --(*this);
    return result;
}

