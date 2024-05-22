//
// Created by irfan on 5/12/24.
//

#ifndef CPP_DSA_BINARYTREENODE_H
#define CPP_DSA_BINARYTREENODE_H

#include <cstddef>

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

    T value;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

private:
    static BinaryTreeNode<T>* BuildTreeFromPreAndInOrderHelper(T* inOrder, T* preOrder, long inOrderStart, long inOrderEnd, long preOrderStart, long preOrderEnd);
};


#endif //CPP_DSA_BINARYTREENODE_H
