//
// Created by irfan on 4/19/24.
//

#include <LinkedList.h>


class LinkedListIndexOutOfBoundException : public std::exception {
    [[nodiscard]] const char * what() const noexcept final {
        return "The provided index is outside the linked list's range.";
    }
};


template<typename T>
LinkedListNode<T>::LinkedListNode(T value, LinkedListNode* next): value{value}, next{next} {
}


template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    length = 0;
}

template<typename T>
void LinkedList<T>::Add(T element) {
    if(head == nullptr) {
        // C++ compiler can resolve this generic type by itself
        head = new LinkedListNode(element);
        ++length;
    } else {
        LinkedListNode<T>* current = head;

        // Finding the last element
        while(current->next != nullptr) {
           current = current->next;
        }

        current->next = new LinkedListNode(element);
        ++length;
    }
}

template<typename T>
void LinkedList<T>::Insert(T element, unsigned long long index) {
    if(index > (length - 1)) {
        throw LinkedListIndexOutOfBoundException();
    }

    if(index == 0) {
        if(head != nullptr) {
            LinkedListNode<T>* newHead = new LinkedListNode(element, head);
            head = newHead;
        } else {
            head = new LinkedListNode(element);
        }
    } else {
        LinkedListNode<T>* previousNode = head;
        unsigned long long previousNodeIndex = 0;

        while(previousNodeIndex != (index - 1)) {
            previousNode = previousNode->next;
            ++previousNodeIndex;
        }

        LinkedListNode<T>* temp = previousNode->next;
        previousNode->next = new LinkedListNode(element, temp);
    }

    ++length;
}

template<typename T>
void LinkedList<T>::Remove(unsigned long long index) {
    if(index > (length - 1)) {
        throw LinkedListIndexOutOfBoundException();
    }

    if(index == 0) {
        LinkedListNode<T>* currentHead = head;
        head = head->next;

        delete currentHead;
    } else {
        LinkedListNode<T>* previousNode = head;
        unsigned long long previousNodeIndex = 0;

        while(previousNodeIndex != (index - 1)) {
            previousNode = previousNode->next;
            ++previousNodeIndex;
        }

        LinkedListNode<T>* nodeToDelete = previousNode->next;
        previousNode->next = previousNode->next->next;

        delete nodeToDelete;
    }

    --length;
}

template<typename T>
T LinkedList<T>::Get(unsigned long long index) {
    if(index > (length - 1)) {
        throw LinkedListIndexOutOfBoundException();
    }

    LinkedListNode<T>* current = head;
    unsigned long long currentIndex = 0;

    while (currentIndex != index) {
        current = current->next;
        ++currentIndex;
    }

    return current->value;
}

template<typename T>
void LinkedList<T>::Print() const {
    LinkedListNode<T>* current = head;

    if(current != nullptr) {
        std::cout << current->value;
    }

    while(current->next != nullptr) {
        std::cout << " -> " << current->next->value;

        current = current->next;
    }

    std::cout << "\n";
}