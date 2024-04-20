//
// Created by irfan on 4/20/24.
//

#include <Stack.h>
#include <exception>


class StackUnderflowException : public std::exception {
    [[nodiscard]] const char * what() const noexcept final {
        return "The stack is empty.";
    }
};


template<typename T>
StackNode<T>::StackNode(T value, StackNode<T> *bottom): value{value}, bottom{bottom} {
}


template<typename T>
Stack<T>::Stack() {
    top = nullptr;
    height = 0;
}

template<typename T>
void Stack<T>::Push(T element) {
    if (top == nullptr) {
        top = new StackNode<T>(element);
        ++height;
    } else {
        StackNode<T>* temp = top;

        top = new StackNode<T>(element, temp);
        ++height;
    }
}

template<typename T>
T Stack<T>::Pop() {
    if(height == 0) {
        throw StackUnderflowException();
    }

    T value = top->value;

    top = top->bottom;
    --height;

    return value;
}

template<typename T>
T Stack<T>::Peek() const{
    if(height == 0) {
        throw StackUnderflowException();
    }

    return top->value;
}
