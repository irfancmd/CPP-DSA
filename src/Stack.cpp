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
    } else {
        StackNode<T>* temp = top;

        top = new StackNode<T>(element, temp);
    }

    ++height;
}

template<typename T>
T Stack<T>::Pop() {
    if(height == 0) {
        throw StackUnderflowException();
    }

    StackNode<T>* topNode = top;
    T value = topNode->value;

    top = top->bottom;
    delete topNode;
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

// Generic is not really needed here, but still we have to put it.
template<typename T>
bool Stack<T>::IsExpressionBalanced(std::string &equation) {
    Stack<char> stack;

    for(char c : equation) {
        if(c == '(' || c == '{' || c == '[') {
            // If we get an opening bracket, push it to the stack
            stack.Push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            // If we get an opening bracket, pop the top item and
            // check if it actually is the opening bracket for the current
            // closing bracket.
            char openingBracket = stack.Pop();

            if((c == ')' && openingBracket == '(') || (c == '}' && openingBracket == '{') || (c == ']' && openingBracket == '['))
            {
                continue;
            } else {
                return false;
            }
        }
    }

    // After iterating through the equation string, we have to check if our stack is empty or not.
    // For a balanced equation, the stack should be empty.
    return stack.height == 0;
}