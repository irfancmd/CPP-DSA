#include <iostream>

#include <LinkedList.h>
#include <Stack.h>
#include <Queue.h>
#include <TreeNode.h>

// To avoid linker error with generics.
// See: https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp
#include "./LinkedList.cpp"
#include "./Stack.cpp"
#include "./Queue.cpp"
#include "./TreeNode.cpp"


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
//    std::cout << list.Get(2) << "\n";
//
//    list.Add(15);
//    list.Add(16);
//
//    list.Print();
//
//    std::cout << list.GetMidPoint() << "\n";
//
//    std::cout << "Merging two sorted lists..." << "\n";
//
//    LinkedList<int> ls1 {};
//    ls1.Add(2);
//    ls1.Add(6);
//    ls1.Add(9);
//
//    ls1.Print();
//
//    LinkedList<int> ls2 {};
//    ls2.Add(1);
//    ls2.Add(3);
//    ls2.Add(5);
//
//    ls2.Print();
//
//    LinkedList<int>* mergedList = LinkedList<int>::MergeSortedLinkedLists(ls1, ls2);
//
//    mergedList->Print();
//
//    std::cout << "Reversing a linked list.\n";
//
//    mergedList->Reverse(mergedList->head);
//    mergedList->Print();
//
//    std::cout << "Reversing a linked list iteratively.\n";
//    mergedList->ReverseIterative(mergedList->head);
//    mergedList->Print();

//    Stack<int> stack {};
//
//    stack.Push(5);
//    stack.Push(6);
//    stack.Push(7);
//
//    std::cout<< stack.Pop() << "\n";
//    std::cout<< stack.Pop() << "\n";
//    std::cout<< stack.Peek() << "\n";
//    std::cout<< stack.Pop() << "\n";
//
//    Queue<int> queue {};
//
//    queue.Enqueue(2);
//    queue.Enqueue(4);
//    queue.Enqueue(6);
//
//    std::cout << queue.Dequeue() << "\n";
//    std::cout << queue.Dequeue() << "\n";
//    std::cout << queue.Dequeue() << "\n";

//    std::string expression1 = "2 + (1 + 3) * [3 + {2 - 1} / 5]";
//    std::string expression2 = "2 + (1 + 3 * [3 + {2 - 1} / 5]";
//    bool isBalanced = Stack<char>::IsExpressionBalanced(expression1);
//
//    if(isBalanced) {
//        std::cout << "The expression is balanced.\n";
//    } else {
//        std::cout << "The expression is not balanced.\n";
//    }

    auto* root = new TreeNode<int> { 10 };
    auto* n1 = new TreeNode<int> { 20 };
    auto* n2 = new TreeNode<int> { 30 };

    root->children->push_back(n1);
    root->children->push_back(n2);

//    TreeNode<int>::PrintTree(root);
    TreeNode<int>::PrintLevelWise(root);

    std::cout << "Number of nodes in the tree: " << TreeNode<int>::CountNumberOfNodes(root) << "\n";

    std::cout << "Height the tree: " << TreeNode<int>::GetHeight(root) << "\n";

    TreeNode<int>::PrintNodeAtDepth(root, 1);
    std::cout << "\n";

    std::cout << "Number of leaves in the tree: " << TreeNode<int>::CountLeaves(root) << "\n";

    TreeNode<int>::PrintPreOrder(root);
    std::cout << "\n";

    TreeNode<int>::PrintPostOrder(root);
    std::cout << "\n";

    return 0;
}
