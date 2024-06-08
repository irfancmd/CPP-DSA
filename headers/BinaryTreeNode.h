//
// Created by irfan on 5/12/24.
//

#ifndef CPP_DSA_BINARYTREENODE_H
#define CPP_DSA_BINARYTREENODE_H

#include <cstddef>
#include <climits>

#include "Triplet.h"
#include "LinkedList.h"

template<typename T>
class BinaryTreeNode {
public:
    explicit BinaryTreeNode(T value);
    ~BinaryTreeNode();
    static size_t CountNodes(BinaryTreeNode<T>* root);
    static void PrintInOrder(BinaryTreeNode<T>* root);
    static BinaryTreeNode<T>* BuildTreeFromPreAndInOrder(T* inOrder, T* preOrder, long size);
    static size_t GetHeight(BinaryTreeNode<T>* root);
    // Diameter is the maximum distance between any two nodes.
    static size_t GetTreeDiameter(BinaryTreeNode<T>* root);
    // Helper function for diameter calculation that avoids calculating height repeatedly.
    static std::pair<size_t, size_t> GetHeightAndDiameter(BinaryTreeNode<T>* root);
    // ***** Binary Search Tree *****
    static BinaryTreeNode<T>* FindOnBinarySearchTree(BinaryTreeNode<T>* root, T valueToSearch);
    static void PrintWithinRange(BinaryTreeNode<T>* root, T start, T end);
    static bool IsBST(BinaryTreeNode<int>* root);
    static int GetMinimum(BinaryTreeNode<int>* root);
    static int GetMaximum(BinaryTreeNode<int>* root);
    static Triplet<bool, int, int> IsBSTOptimized(BinaryTreeNode<int>* root);
    static bool IsBstOptimized2(BinaryTreeNode<int>* root, int min = INT_MIN, int max = INT_MAX);
    static BinaryTreeNode<int>* MakeBstFromSortedArray(int* arr, int start, int end);
    static std::pair<LinkedListNode<T>*, LinkedListNode<T>*> BstToLinkedList(BinaryTreeNode<T>* root);

    T value;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

private:
    static BinaryTreeNode<T>* BuildTreeFromPreAndInOrderHelper(T* inOrder, T* preOrder, long inOrderStart, long inOrderEnd, long preOrderStart, long preOrderEnd);
};


#endif //CPP_DSA_BINARYTREENODE_H
