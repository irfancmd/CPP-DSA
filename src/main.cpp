#include <iostream>

#include <LinkedList.h>
#include <Stack.h>

// To avoid linker error with generics.
// See: https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp
#include "./LinkedList.cpp"
#include "./Stack.cpp"

int main() {
    std::cout << "HELLO\n";

//    LinkedList<int> list {};
//
//    list.Add(5);
//    list.Add(10);
//    list.Add(12);
//
//    list.Insert(20, 2);
//
//    list.Print();
//
//    list.Remove(1);
//
//    list.Print();
//
//    std::cout << list.length << "\n";
//
//    std::cout << list.Get(2);

    Stack<int> stack {};

    stack.Push(5);
    stack.Push(6);
    stack.Push(7);

    std::cout<< stack.Pop() << "\n";
    std::cout<< stack.Pop() << "\n";
    std::cout<< stack.Peek() << "\n";
    std::cout<< stack.Pop() << "\n";

    return 0;
}