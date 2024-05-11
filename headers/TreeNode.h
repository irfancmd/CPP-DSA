//
// Created by irfan on 4/27/24.
//

#ifndef CPP_DSA_TREENODE_H
#define CPP_DSA_TREENODE_H

#include <vector>
#include <queue>

template<typename T>
class TreeNode {
public:
    explicit TreeNode(T value);
    ~TreeNode();
    static void PrintTree(TreeNode<T>* root);
    static void PrintLevelWise(TreeNode<T>* root);
    static size_t CountNumberOfNodes(TreeNode<T>* root);
    static size_t GetHeight(TreeNode<T>* root);
    static void PrintNodeAtDepth(TreeNode<T>* root, size_t depth);
    static size_t CountLeaves(TreeNode<T>* root);
    static void PrintPreOrder(TreeNode<T>* root);
    static void PrintPostOrder(TreeNode<T>* root);

    T value;
    std::vector<TreeNode<T>*>* children;
};


#endif //CPP_DSA_TREENODE_H
