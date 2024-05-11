//
// Created by irfan on 4/27/24.
//
#include <iostream>

#include "TreeNode.h"

template<typename T>
TreeNode<T>::TreeNode(T value): value{value} {
    this->children = new std::vector<TreeNode<T>*>;
}

template<typename T>
TreeNode<T>::~TreeNode() {
    delete this->children;
}

template<typename T>
void TreeNode<T>::PrintTree(TreeNode<T>* root) {
    // This is not the base case. It is an "edge" case
    // to prevent errors. The base case is implicitly
    // handled by the for loop below.
    if(root == nullptr) return;

    std::cout << root->value << ": ";

    // Print the children of the current node
    for(std::size_t i = 0; i < root->children->size(); ++i) {
       // Using "at" method in place of [] notation here because it's safe and easier to use with pointers.
       std::cout << root->children->at(i)->value <<  " ";
    }
    std::cout << "\n";

    // Now, execute this same method for each child
    for(std::size_t i = 0; i < root->children->size(); ++i) {
        PrintTree(root->children->at(i));
    }
}

template<typename T>
void TreeNode<T>::PrintLevelWise(TreeNode<T> *root) {
    std::queue<TreeNode<T>*> nodeQueue;

    nodeQueue.push(root);

    while(!nodeQueue.empty()){
        TreeNode<T>* node = nodeQueue.front();
        nodeQueue.pop();

        std::cout << node->value << ": ";

        for(int i = 0; i < node->children->size(); ++i) {
            std::cout << node->children->at(i)->value;
            std::cout << " ";

            nodeQueue.push(node->children->at(i));
        }

        std::cout << "\n";
    }
}

template<typename T>
size_t TreeNode<T>::CountNumberOfNodes(TreeNode<T> *root) {
    size_t ans = 1;

    for(size_t i = 0; i < root->children->size(); ++i) {
        ans += CountNumberOfNodes(root->children->at(i));
    }

    return ans;
}

template<typename T>
size_t TreeNode<T>::GetHeight(TreeNode<T> *root) {
    size_t maxHeight = 0;

    for(size_t i = 0; i < root->children->size(); ++i) {
        size_t height = GetHeight(root->children->at(i));

        if(height > maxHeight) {
            maxHeight = height;
        }
    }

    return maxHeight + 1;
}

template<typename T>
void TreeNode<T>::PrintNodeAtDepth(TreeNode<T> *root, size_t depth) {
    if(depth == 0) {
        std::cout << root->value << " ";
    }

    for(size_t i = 0; i < root->children->size(); ++i) {
        PrintNodeAtDepth(root->children->at(i), depth - 1);
    }
}

template<typename T>
size_t TreeNode<T>::CountLeaves(TreeNode<T> *root) {
    if(root->children->empty()) {
        return 1;
    }

    size_t ans = 0;

    for(size_t i = 0; i < root->children->size(); ++i) {
        ans += CountLeaves(root->children->at(i));
    }

    return ans;
}

template<typename T>
void TreeNode<T>::PrintPreOrder(TreeNode<T> *root) {
    std::cout << root->value << " ";

    for(size_t i = 0; i < root->children->size(); ++i) {
        PrintPreOrder(root->children->at(i));
    }
}

template<typename T>
void TreeNode<T>::PrintPostOrder(TreeNode<T> *root) {
    for(size_t i = 0; i < root->children->size(); ++i) {
        PrintPreOrder(root->children->at(i));
    }

    std::cout << root->value << " ";
}
