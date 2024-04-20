//
// Created by irfan on 4/19/24.
//

#ifndef CPP_DSA_LINKEDLIST_H
#define CPP_DSA_LINKEDLIST_H

#include <iostream>

template<typename T>
class LinkedListNode {
public:
    explicit LinkedListNode(T value, LinkedListNode* next = nullptr);

    LinkedListNode* next;
    T value;
};


template<typename T>
class LinkedList {
public:
    LinkedList();
    void Add(T element);
    void Insert(T element, unsigned long long index);
    void Remove(unsigned long long index);
    T Get(unsigned long long index);
    void Print() const;

    LinkedListNode<T>* head;
    unsigned long long length;
};


#endif
