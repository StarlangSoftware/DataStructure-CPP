//
// Created by Olcay Taner YILDIZ on 30.06.2022.
//

#ifndef DATASTRUCTURE_BTREE_H
#define DATASTRUCTURE_BTREE_H

#include "BTreeNode.h"

template <class T> class BTree {
public:
    BTreeNode<T>* root = nullptr;
    typedef int(*ComparatorType)(T, T);
    ComparatorType comparator;
    int d;
    BTree(int d, ComparatorType comparator);
    ~BTree();
    BTreeNode<T>* search(const T& value);
    void insert(const T& data);
};

template<class T> BTree<T>::BTree(int d, ComparatorType comparator) {
    this->comparator = comparator;
    this->d = d;
}

template<class T>
BTree<T>::~BTree() {
    delete root;
}

template<class T> BTreeNode<T> *BTree<T>::search(const T& value) {
    int child;
    BTreeNode<T>* b;
    b = root;
    while (!b->leaf){
        child = b->position(value, comparator);
        if (child < b->m && b->K[child] == value){
            return b;
        }
        b = b->children[child];
    }
    child = b->position(value, comparator);
    if (child < b->m && b->K[child] == value){
        return b;
    }
    return nullptr;
}

template<class T> void BTree<T>::insert(const T& data) {
    BTreeNode<T>* s;
    if (root == nullptr){
        root = new BTreeNode<T>(d);
    }
    if (root->leaf){
        s = root->insertLeaf(data, comparator);
        if (s != nullptr){
            BTreeNode<T>* tmp = root;
            root = new BTreeNode<T>(tmp, s, tmp->K[d], d);
        }
    } else {
        s = root->insertNode(data, comparator, true);
        if (s != nullptr){
            root = s;
        }
    }
}

#endif //DATASTRUCTURE_BTREE_H
