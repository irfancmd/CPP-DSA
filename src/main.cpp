#include <iostream>

#include <LinkedList.h>
#include <Stack.h>
#include <Queue.h>
#include <TreeNode.h>
#include <BinaryTreeNode.h>

// To avoid linker error with generics.
// See: https://www.codeproject.com/Articles/48575/How-to-Define-a-Template-Class-in-a-h-File-and-Imp
#include "./LinkedList.cpp"
#include "./Stack.cpp"
#include "./Queue.cpp"
#include "./TreeNode.cpp"
#include "./BinaryTreeNode.cpp"


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

//    auto* root = new TreeNode<int> { 10 };
//    auto* n1 = new TreeNode<int> { 20 };
//    auto* n2 = new TreeNode<int> { 30 };
//
//    root->children->push_back(n1);
//    root->children->push_back(n2);
//
////    TreeNode<int>::PrintTree(root);
//    TreeNode<int>::PrintLevelWise(root);
//
//    std::cout << "Number of nodes in the tree: " << TreeNode<int>::CountNumberOfNodes(root) << "\n";
//
//    std::cout << "Height the tree: " << TreeNode<int>::GetHeight(root) << "\n";
//
//    TreeNode<int>::PrintNodeAtDepth(root, 1);
//    std::cout << "\n";
//
//    std::cout << "Number of leaves in the tree: " << TreeNode<int>::CountLeaves(root) << "\n";
//
//    TreeNode<int>::PrintPreOrder(root);
//    std::cout << "\n";
//
//    TreeNode<int>::PrintPostOrder(root);
//    std::cout << "\n";

//    auto tn1 = new BinaryTreeNode<int>(10);
//    auto tn2 = new BinaryTreeNode<int>(15);
//    auto tn3 = new BinaryTreeNode<int>(20);
//
//    tn1->left = tn2;
//    tn1->right = tn3;
//
//    auto tn4 = new BinaryTreeNode<int>(25);
//
//    tn3->left = tn4;
//
//    std::cout << "Number of nodes in the binary tree: " << BinaryTreeNode<int>::CountNodes(tn1) << "\n";
//
//    BinaryTreeNode<int>::PrintInOrder(tn1);
//
//    std::cout << "\n";

//    int inOrder[] = { 4, 2, 5, 1, 8, 6, 9, 3, 7 };
//    int preOrder[] = { 1, 2, 4, 5, 3, 6, 8, 9, 7 };
//
//    BinaryTreeNode<int>* root = BinaryTreeNode<int>::BuildTreeFromPreAndInOrder(inOrder, preOrder, 9);
//
//    // We can match it to the inOrder input to verify if the tree building is correct
//    BinaryTreeNode<int>::PrintInOrder(root);

//     auto root = new BinaryTreeNode<int> { 1 };
//     root->left = new BinaryTreeNode<int> { 2 };
//     root->right = new BinaryTreeNode<int> { 3 };
//
//     std::pair<size_t, size_t> heightAndDiameter = BinaryTreeNode<int>::GetHeightAndDiameter(root);
//
//     std::cout << "Height: " << heightAndDiameter.first << "\n";
//     std::cout << "Diameter: " << heightAndDiameter.second << "\n";

    auto root = new BinaryTreeNode<int> { 5 };
    root->left = new BinaryTreeNode<int> { 3 };
    root->left->left = new BinaryTreeNode<int> { 2 };
    root->left->right = new BinaryTreeNode<int> { 4 };
    root->right = new BinaryTreeNode<int> { 7 };
    root->right->left = new BinaryTreeNode<int> { 6 };
    root->right->right = new BinaryTreeNode<int> { 8 };

//        auto node = BinaryTreeNode<int>::FindOnBinarySearchTree(root, 2);
//        std::cout << node->value << "\n";

//    BinaryTreeNode<int>::PrintWithinRange(root, 3, 7);
//    std::cout << "\n";

//    std::cout << BinaryTreeNode<int>::IsBST(root) << "\n";
//    std::cout << BinaryTreeNode<int>::IsBSTOptimized(root).first << "\n";

//    std::cout << BinaryTreeNode<int>::IsBstOptimized2(root) << "\n";

//    int sortedArr[] = { 1, 2, 3, 4, 5, 6, 7, 8};
//
//    BinaryTreeNode<int>* constructedRoot = BinaryTreeNode<int>::MakeBstFromSortedArray(sortedArr, 0, 7);
//
//    BinaryTreeNode<int>::PrintInOrder(constructedRoot);
//
//    bool isOptimized = BinaryTreeNode<int>::IsBstOptimized2(constructedRoot);
//
//    std::cout << "\n";
//
//    std::cout << isOptimized << "\n";

    auto linkedListInfo = BinaryTreeNode<int>::BstToLinkedList(root);

    LinkedListNode<int>* head = linkedListInfo.first;

    if(head == nullptr) {
        std::cout << "NULL\n";
    }

    while(head != nullptr) {
        std::cout << head->value << " ";
        head = head->next;
    }

    std::cout << "\n";

    return 0;
}
