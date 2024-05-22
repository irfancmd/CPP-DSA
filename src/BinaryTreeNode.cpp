//
// Created by irfan on 5/12/24.
//

#include <iostream>
#include "BinaryTreeNode.h"

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T value): value {value} {
    left = nullptr;
    right = nullptr;
}

template<typename T>
BinaryTreeNode<T>::~BinaryTreeNode() {
    delete left;
    delete right;
}

template<typename T>
size_t BinaryTreeNode<T>::CountNodes(BinaryTreeNode<T> *root) {
    if(root == nullptr) {
        return 0;
    }

    return 1 + CountNodes(root->left) + CountNodes(root->right);
}

template<typename T>
void BinaryTreeNode<T>::PrintInOrder(BinaryTreeNode<T> *root) {
    if(root == nullptr) {
        return;
    }

    PrintInOrder(root->left);
    std::cout << root->value << " ";
    PrintInOrder(root->right);
}

template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::BuildTreeFromPreAndInOrder(T *inOrder, T *preOrder, long size) {
    return BuildTreeFromPreAndInOrderHelper(inOrder, preOrder, 0, size - 1, 0, size - 1);
}

template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::BuildTreeFromPreAndInOrderHelper(T *inOrder, T *preOrder, long inOrderStart,
                                                                      long inOrderEnd, long preOrderStart,
                                                                       long preOrderEnd)
{
    if(inOrderStart > inOrderEnd) {
        return nullptr;
    }

    T rootData = preOrder[preOrderStart];

   // std::cout << rootData << "\n";

    long rootIndex = -1;

    for(long i = inOrderStart; i <= inOrderEnd; ++i) {
        if(inOrder[i] == rootData) {
            rootIndex = i;
            break;
        }
    }

    long leftInOrderStart = inOrderStart;
    long leftInOrderEnd = rootIndex - 1;
    long leftPreOrderStart = preOrderStart + 1;
    long leftPreOrderEnd = leftInOrderEnd - leftInOrderStart + leftPreOrderStart;

    long rightPreOrderStart = leftPreOrderEnd + 1;
    long rightPreOrderEnd = preOrderEnd;
    long rightInOrderStart = rootIndex + 1;
    long rightInOrderEnd = inOrderEnd;

     BinaryTreeNode<T>* root = new BinaryTreeNode<T>(rootData);

     root->left = BuildTreeFromPreAndInOrderHelper(inOrder, preOrder, leftInOrderStart, leftInOrderEnd, leftPreOrderStart, leftPreOrderEnd);
     root->right = BuildTreeFromPreAndInOrderHelper(inOrder, preOrder, rightInOrderStart, rightInOrderEnd, rightPreOrderStart, rightPreOrderEnd);

     return root;
}

template<typename T>
size_t BinaryTreeNode<T>::GetHeight(BinaryTreeNode<T> *root) {
    if(root == nullptr) {
        return 0;
    }

    size_t leftHeight = GetHeight(root->left);
    size_t rightHeight = GetHeight(root->right);

    return 1 + std::max(leftHeight, rightHeight);
}

template<typename T>
size_t BinaryTreeNode<T>::GetTreeDiameter(BinaryTreeNode<T> *root) {
    if(root == nullptr) {
        return 0;
    }

    size_t option1 = BinaryTreeNode<T>::GetHeight(root->left) + BinaryTreeNode<T>::GetHeight(root->right);
    size_t option2 = BinaryTreeNode<T>::GetTreeDiameter(root->left);
    size_t option3 = BinaryTreeNode<T>::GetTreeDiameter(root->right);

    return std::max(option1, std::max(option2, option3));
}

template<typename T>
std::pair<size_t, size_t> BinaryTreeNode<T>::GetHeightAndDiameter(BinaryTreeNode<T> *root) {
    if(root == nullptr) {
        // We're returning the pair by value. So, no need for dynamic allocation.
        std::pair<size_t, size_t> p;
        p.first = 0;
        p.second = 0;

        return p;
    }

    std::pair<size_t, size_t> leftAnswer = GetHeightAndDiameter(root->left);
    std::pair<size_t, size_t> rightAnswer = GetHeightAndDiameter(root->right);

    size_t leftHeight = leftAnswer.first;
    size_t leftDiameter = leftAnswer.second;
    size_t rightHeight = rightAnswer.first;
    size_t rightDiameter = rightAnswer.second;

    size_t height = 1 + std::max(leftHeight, rightHeight);
    size_t diameter = std::max(leftHeight + rightHeight, std::max(leftDiameter, rightDiameter));

    std::pair<size_t, size_t> p;
    p.first = height;
    p.second = diameter;

    return p;
}