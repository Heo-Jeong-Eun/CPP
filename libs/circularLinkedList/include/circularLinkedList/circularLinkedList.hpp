//
// Created by jeong on 2023-11-27.
//

#ifndef CPP_SINGLELINKEDLIST_HPP
#define CPP_SINGLELINKEDLIST_HPP

#include <iostream>
#include <algorithm>


struct doubleLinkedListNode {
    int data;
    doubleLinkedListNode *next;
    doubleLinkedListNode *prev;
};


class circularLinkedList {
public:
    using node = doubleLinkedListNode;
    using nodePtr = node *;

    struct circularLinkedListIterator {
    private:
        nodePtr ptr;
    public:
        circularLinkedListIterator(nodePtr p) : ptr(p) {}

        int &operator*() { return ptr->data; }

        nodePtr get() { return ptr; }

        circularLinkedListIterator &operator++();

        circularLinkedListIterator operator++(int);

        circularLinkedListIterator &operator--();

        circularLinkedListIterator operator--(int);

        bool operator==(const circularLinkedListIterator &other) {
            return ptr == other.ptr;
        }

        bool operator!=(const circularLinkedListIterator &other) {
            return ptr != other.ptr;
        }
    };

private:
    nodePtr front;
    nodePtr back;
public:
    circularLinkedList() : front(nullptr), back(nullptr) {}

    circularLinkedList(const int &newData);

//    circularLinkedList(const singlyLinkedList &other);

//    circularLinkedList(const std::initializer_list<int> &ilist);
    void insert(const circularLinkedListIterator pos, int step, int value);

    void erase(int value);

    void push_front(int value);

    void pop_front();

    void push_back(int value);

    void pop_back();

    circularLinkedListIterator begin() { return circularLinkedListIterator(front); }

    circularLinkedListIterator end() { return circularLinkedListIterator(back); }

    circularLinkedListIterator begin() const { return circularLinkedListIterator(front); }

    circularLinkedListIterator end() const { return circularLinkedListIterator(back); }

};
void print(const circularLinkedList &list);

#endif //CPP_SINGLELINKEDLIST_HPP

