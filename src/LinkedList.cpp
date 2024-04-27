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
        // C++ compiler can resolve this generic type by itself.
        // We're putting the node in dynamic (heap) memory, since we don't want
        // to lose it when it goes out of the scope of this function.
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
T LinkedList<T>::GetMidPoint() const {
    LinkedListNode<T>* slowPointer = head;
    LinkedListNode<T>* fastPointer = head;

    if(length == 0) {
        throw LinkedListIndexOutOfBoundException();
    }

    while(fastPointer->next != nullptr && fastPointer->next->next != nullptr) {
        fastPointer = fastPointer->next->next;
        slowPointer = slowPointer->next;
    }

    return slowPointer->value;
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

template<typename T>
LinkedList<T>* LinkedList<T>::MergeSortedLinkedLists(const LinkedList<T>& list1, const LinkedList<T>& list2) {
    auto* mergedList = new LinkedList<T>;

    LinkedListNode<T>* list1Pointer = list1.head;
    LinkedListNode<T>* list2Pointer = list2.head;

    while(list1Pointer != nullptr && list2Pointer != nullptr) {
       if(list1Pointer->value < list2Pointer->value) {
           mergedList->Add(list1Pointer->value);

           list1Pointer = list1Pointer->next;
       } else {
           mergedList->Add(list2Pointer->value);

           list2Pointer = list2Pointer->next;
       }
    }

    while(list1Pointer != nullptr) {
        mergedList->Add(list1Pointer->value);

        list1Pointer = list1Pointer->next;
    }

    while(list2Pointer != nullptr) {
        mergedList->Add(list2Pointer->value);

        list2Pointer = list2Pointer->next;
    }

    return mergedList;
}

template<typename T>
LinkedListNode<T>* LinkedList<T>::Reverse(LinkedListNode<T>* currentHead)
{
    if(currentHead == nullptr || currentHead->next == nullptr) {
        return currentHead;
    }

    LinkedListNode<T>* newHead = Reverse(currentHead->next);

    // By determining tail like this, we can avoid getting the tail using a while
    // loop, which would result in O(n^2) time complexity.
    LinkedListNode<T>* currentTail = currentHead->next;
    currentTail->next = currentHead;
    currentHead->next = nullptr;

    // Update the object's head as well
    this->head = newHead;

    return newHead;
}

template<typename T>
LinkedListNode<T>* LinkedList<T>::ReverseIterative(LinkedListNode<T> *currentHead) {
    LinkedListNode<T>* current = currentHead;
    LinkedListNode<T>* next = current->next;
    LinkedListNode<T>* prev = nullptr;

    while(current != nullptr && next != nullptr) {
        current->next = prev;

        prev = current;
        current = next;

        next = next->next;
    }

    // Now, add the very last node of the current list, which will be the head of the new one.
    current->next = prev;

    // Update the object's head as well
    this->head = current;

    return current;
}

