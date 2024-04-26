//
// Created by irfan on 4/26/24.
//

#ifndef CPP_DSA_QUEUE_H
#define CPP_DSA_QUEUE_H


template<typename T>
class QueueNode {
public:
    explicit QueueNode(T value, QueueNode* next = nullptr);

    QueueNode* next;
    T value;
};


template<typename T>
class Queue {
public:
    Queue();
    void Enqueue(T element);
    T Dequeue();

    QueueNode<T>* first;
    unsigned long long length;
};


#endif //CPP_DSA_QUEUE_H
