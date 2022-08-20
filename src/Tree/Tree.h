//
// Created by Olcay Taner YILDIZ on 29.06.2022.
//

#ifndef DATASTRUCTURE_TREE_H
#define DATASTRUCTURE_TREE_H

#include "TreeNode.h"

template <class T> class Tree{
protected:
    TreeNode<T>* root = nullptr;
    typedef int(*ComparatorType)(T, T);
    ComparatorType comparator;
    void insertChild(TreeNode<T>* parent, TreeNode<T>* child);
public:
    explicit Tree(ComparatorType comparator);
    ~Tree();
    TreeNode<T>* search(T value);
    void insert(TreeNode<T>* node);
    void insert(T data);
};

template<class T> TreeNode<T> *Tree<T>::search(T value) {
    TreeNode<T>* d = root;
    while (d != nullptr){
        if (comparator(d->data, value) == 0){
            return d;
        } else {
            if (comparator(d->data, value) > 0){
                d = d->left;
            } else {
                d = d->right;
            }
        }
    }
    return nullptr;
}

template<class T> Tree<T>::Tree(ComparatorType comparator) {
    this->comparator = comparator;
}

template<class T> void Tree<T>::insertChild(TreeNode<T> *parent, TreeNode<T> *child) {
    if (parent == nullptr){
        root = child;
    } else {
        if (comparator(child->data, parent->data) < 0){
            parent->left = child;
        } else {
            parent->right = child;
        }
    }
}

template<class T> void Tree<T>::insert(TreeNode<T> *node) {
    TreeNode<T>* y = nullptr;
    TreeNode<T>* x = root;
    while (x != nullptr){
        y = x;
        if (comparator(node->data, x->data) < 0){
            x = x->left;
        } else {
            x = x->right;
        }
    }
    insertChild(y, node);
}

template<class T> void Tree<T>::insert(T data) {
    insert(new TreeNode<T>(data));
}

template<class T>
Tree<T>::~Tree() {
    delete root;
}

#endif //DATASTRUCTURE_TREE_H
