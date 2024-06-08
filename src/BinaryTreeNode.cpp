//
// Created by irfan on 5/12/24.
//

#include <iostream>
#include <climits>

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

// ***** Binary Search Tree *****

template<typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::FindOnBinarySearchTree(BinaryTreeNode<T> *root, T valueToSearch) {
    if(root == nullptr) {
        return nullptr;
    }

    if(root->value == valueToSearch) {
        return root;
    } else if (valueToSearch < root->value) {
       return FindOnBinarySearchTree(root->left, valueToSearch);
    } else {
        return FindOnBinarySearchTree(root->right, valueToSearch);
    }
}

template<typename T>
void BinaryTreeNode<T>::PrintWithinRange(BinaryTreeNode<T> *root, T start, T end) {
   if(root == nullptr) {
       return;
   }

   if(root->value >= start && root->value <= end) {
      std::cout << root->value << " ";

      BinaryTreeNode<T>::PrintWithinRange(root->left, start, end);
      BinaryTreeNode<T>::PrintWithinRange(root->right, start, end);
   } else if (root->value > end) {
       BinaryTreeNode<T>::PrintWithinRange(root->left, start, end);
   } else if (root->value < start) {
       BinaryTreeNode<T>::PrintWithinRange(root->right, start, end);
   }
}

template<typename T>
int BinaryTreeNode<T>::GetMinimum(BinaryTreeNode<int> *root) {
    if(root == nullptr) {
        return INT_MAX;
    }

    return std::min(root->value, std::min(BinaryTreeNode<int>::GetMinimum(root->left), BinaryTreeNode<int>::GetMinimum(root->right)));
}

template<typename T>
int BinaryTreeNode<T>::GetMaximum(BinaryTreeNode<int> *root) {
    if(root == nullptr) {
        return INT_MIN;
    }

    return std::max(root->value, std::max(BinaryTreeNode<int>::GetMaximum(root->left), BinaryTreeNode<int>::GetMaximum(root->right)));
}

template<typename T>
bool BinaryTreeNode<T>::IsBST(BinaryTreeNode<int> *root) {
    if(root == nullptr) {
        return true;
    }

    int leftMax = BinaryTreeNode<int>::GetMaximum(root->left);
    int rightMin = BinaryTreeNode<int>::GetMinimum(root->right);

    bool output = (root->value > leftMax) && (root->value <= rightMin) && BinaryTreeNode<int>::IsBST(root->left) && BinaryTreeNode<int>::IsBST(root->right);

    return output;
}

template<typename T>
Triplet<bool, int, int> BinaryTreeNode<T>::IsBSTOptimized(BinaryTreeNode<int> *root) {
    if(root == nullptr) {
        // First: IsBST, Second: Minimum, Third: Maximum
        return Triplet { true, INT_MAX, INT_MIN };
    }

    Triplet<bool, int, int> leftOutput = BinaryTreeNode<T>::IsBSTOptimized(root->left);
    Triplet<bool, int, int> rightOutput = BinaryTreeNode<T>::IsBSTOptimized(root->right);

    int minimum = std::min(root->value, std::min(leftOutput.second, rightOutput.second));
    int maximum = std::max(root->value, std::max(leftOutput.third, rightOutput.third));

    bool isBstFinal = (root->value > leftOutput.third)
            && (root->value <= rightOutput.second)
            && leftOutput.first
            && rightOutput.first;

    return Triplet { isBstFinal, minimum, maximum };
}

template<typename T>
bool BinaryTreeNode<T>::IsBstOptimized2(BinaryTreeNode<int> *root, int min, int max) {
    if(root == nullptr) {
        return true;
    }

    if(root->value < min && root->value > max) {
        return false;
    }

    bool isLeftOk = BinaryTreeNode<T>::IsBstOptimized2(root->left, min, root->value - 1);
    bool isRightOk = BinaryTreeNode<T>::IsBstOptimized2(root->right, root->value, max);

    return isLeftOk && isRightOk;
}

template<typename T>
BinaryTreeNode<int>* BinaryTreeNode<T>::MakeBstFromSortedArray(int *arr, int start, int end) {
    if(start > end) {
        return nullptr;
    }

    if(start == end) {
        return new BinaryTreeNode<int> { arr[start] };
    }

    int partitionLength = (end - start) + 1;

    int midIndex = start + (partitionLength / 2);

    BinaryTreeNode<int>* node = new BinaryTreeNode<int> { arr[midIndex] };

    node->left = BinaryTreeNode<T>::MakeBstFromSortedArray(arr, start, midIndex - 1);
    node->right = BinaryTreeNode<T>::MakeBstFromSortedArray(arr, midIndex + 1, end);

    return node;
}

template<typename T>
std::pair<LinkedListNode<T>*, LinkedListNode<T>*> BinaryTreeNode<T>::BstToLinkedList(BinaryTreeNode<T> *root) {
    if (root == nullptr) {
        return std::make_pair(nullptr, nullptr);
    }

    LinkedListNode<T>* current = new LinkedListNode<T> { root->value };

    std::pair<LinkedListNode<T>*, LinkedListNode<T>*> leftResult = BinaryTreeNode<T>::BstToLinkedList(root->left);
    if(leftResult.second != nullptr) {
        leftResult.second->next = current;
    }

    std::pair<LinkedListNode<T>*, LinkedListNode<T>*> rightResult = BinaryTreeNode<T>::BstToLinkedList(root->right);
    current->next = rightResult.first;

    if(leftResult.first != nullptr && rightResult.second != nullptr) {
        return std::make_pair(leftResult.first, rightResult.second);
    } else if(leftResult.first == nullptr && rightResult.second != nullptr) {
        return std::make_pair(current, rightResult.second);
    } else if(leftResult.first != nullptr && rightResult.second == nullptr) {
        return std::make_pair(leftResult.first, current);
    } else {
        // Both leftResult's head and rightResult's tail is null
        return std::make_pair(current, current);
    }
}