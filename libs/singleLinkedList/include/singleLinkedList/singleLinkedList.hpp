//
// Created by jeong on 2023-11-27.
//

#ifndef CPP_SINGLELINKEDLIST_HPP
#define CPP_SINGLELINKEDLIST_HPP

#include <iostream>
#include <algorithm>

struct singlyLinkedListNode {
    int data;
    singlyLinkedListNode *next;
};

class singlyLinkedList {
public:
    using node = singlyLinkedListNode;
    using nodePtr = node *;

    struct singlyLinkedListIterator {
    private:
        nodePtr ptr;
    public:
        singlyLinkedListIterator(nodePtr p) : ptr(p) {}

        int &operator*() { return ptr->data; }

        nodePtr get() { return ptr; }

        singlyLinkedListIterator &operator++();

        singlyLinkedListIterator operator++(int);

        friend bool operator==(const singlyLinkedListIterator &left, const singlyLinkedListIterator &right) {
            return left.ptr == right.ptr;
        }

        friend bool operator!=(const singlyLinkedListIterator &left, const singlyLinkedListIterator &right) {
            return left.ptr != right.ptr;
        }
    };

private:
    nodePtr head;
public:
    singlyLinkedList() = default;

    singlyLinkedList(const singlyLinkedList &other);

    singlyLinkedList(const std::initializer_list<int> &ilist);

    void push_front(int value);

    void pop_front();

    singlyLinkedListIterator begin() { return singlyLinkedListIterator(head); }

    singlyLinkedListIterator end() { return singlyLinkedListIterator(nullptr); }

    singlyLinkedListIterator begin() const { return singlyLinkedListIterator(head); }

    singlyLinkedListIterator end() const { return singlyLinkedListIterator(nullptr); }

};


#endif //CPP_SINGLELINKEDLIST_HPP

