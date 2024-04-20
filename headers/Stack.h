//
// Created by irfan on 4/20/24.
//

#ifndef CPP_DSA_STACK_H
#define CPP_DSA_STACK_H


template<typename T>
class StackNode {
public:
    explicit StackNode(T value, StackNode* bottom = nullptr);

    StackNode* bottom;
    T value;
};


template<typename T>
class Stack {
public:
    Stack();
    void Push(T element);
    T Pop();
    T Peek() const;

    StackNode<T>* top;
    unsigned long long height;
};


#endif //CPP_DSA_STACK_H
