//
// Created by irfan on 4/26/24.
//

#include <Queue.h>
#include <exception>

class QueueEmptyException : public std::exception {
    [[nodiscard]] const char * what() const noexcept override {
        return "The queue is empty.";
    }
};


template<typename T>
QueueNode<T>::QueueNode(T value, QueueNode<T> *next) : value{value}, next{next} {
}


template<typename T>
Queue<T>::Queue() {
    first = nullptr;
    length = 0;
}


template<typename T>
void Queue<T>::Enqueue(T element) {
    if(first == nullptr) {
        first = new QueueNode<T>(element, nullptr);
    } else {
        QueueNode<T>* current = first;

        while(current->next != nullptr) {
            current = current->next;
        }

        current->next = new QueueNode<T>(element, nullptr);
    }

    ++length;
}


template<typename T>
T Queue<T>::Dequeue() {
    if(length == 0) {
        throw QueueEmptyException();
    }

    if(length == 1) {
        T val = first->value;

        this->first = nullptr;
        --length;

        return val;
    } else {
        QueueNode<T>* firstNode = first;
        T val = firstNode->value;

        this->first = first->next;

        delete firstNode;
        --length;

        return val;
    }
}