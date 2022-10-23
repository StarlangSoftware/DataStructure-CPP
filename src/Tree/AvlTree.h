//
// Created by Olcay Taner YILDIZ on 30.06.2022.
//

#ifndef DATASTRUCTURE_AVLTREE_H
#define DATASTRUCTURE_AVLTREE_H

#include "Tree.h"
#include "AvlTreeNode.h"
#include "../Stack.h"

template <class T> class AvlTree : public Tree<T>{
public:
    typedef int(*ComparatorType)(T, T);
    explicit AvlTree(ComparatorType comparator);
    int height(AvlTreeNode<T>* d) const;
    void insert(const T& item);
private:
    AvlTreeNode<T>* rotateLeft(AvlTreeNode<T>* k2);
    AvlTreeNode<T>* rotateRight(AvlTreeNode<T>* k1);
    AvlTreeNode<T>* doubleRotateLeft(AvlTreeNode<T>* k3);
    AvlTreeNode<T>* doubleRotateRight(AvlTreeNode<T>* k1);
    void insert(AvlTreeNode<T>* node);
};

template<class T> AvlTree<T>::AvlTree(AvlTree::ComparatorType comparator):Tree<T>(comparator) {
}

template<class T> int AvlTree<T>::height(AvlTreeNode<T> *d) const{
    if (d == nullptr){
        return 0;
    } else {
        return d->height;
    }
}

template<class T> AvlTreeNode<T> *AvlTree<T>::rotateLeft(AvlTreeNode<T> *k2) {
    auto* k1 = (AvlTreeNode<T>*) k2->left;
    k2->left = k1->right;
    k1->right = k2;
    k2->height = max(height((AvlTreeNode<T>*) k2->left), height((AvlTreeNode<T>*) k2->right)) + 1;
    k1->height = max(height((AvlTreeNode<T>*) k1->left), ((AvlTreeNode<T>*) k1->right)->height) + 1;
    return k1;
}

template<class T> AvlTreeNode<T> *AvlTree<T>::rotateRight(AvlTreeNode<T> *k1) {
    auto* k2 = (AvlTreeNode<T>*) k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k2->height = max(((AvlTreeNode<T>*) k2->left)->height, height((AvlTreeNode<T>*) k2->right)) + 1;
    k1->height = max(height((AvlTreeNode<T>*) k1->left), height((AvlTreeNode<T>*) k1->right)) + 1;
    return k2;
}

template<class T> AvlTreeNode<T> *AvlTree<T>::doubleRotateLeft(AvlTreeNode<T> *k3) {
    k3->left = rotateRight((AvlTreeNode<T>*) k3->left);
    return rotateLeft(k3);
}

template<class T> AvlTreeNode<T> *AvlTree<T>::doubleRotateRight(AvlTreeNode<T> *k1) {
    k1->right = rotateLeft((AvlTreeNode<T>*) k1->right);
    return rotateRight(k1);
}

template<class T> void AvlTree<T>::insert(AvlTreeNode<T> *node) {
    int LEFT = 1, RIGHT = 2;
    AvlTreeNode<T>* y = nullptr;
    AvlTreeNode<int>* x = (AvlTreeNode<T> *) this->root;
    AvlTreeNode<int>* t;
    int dir1 = 0, dir2 = 0;
    Stack<AvlTreeNode<T>*> c = Stack<AvlTreeNode<T>*>();
    while (x != nullptr){
        y = x;
        c.push(y);
        dir1 = dir2;
        if (this->comparator(node->data, x->data) < 0){
            x = (AvlTreeNode<T>*) x->left;
            dir2 = LEFT;
        } else {
            x = (AvlTreeNode<T>*) x->right;
            dir2 = RIGHT;
        }
    }
    this->insertChild(y, node);
    while (!c.isEmpty()){
        x = c.pop();
        x->height = max(height((AvlTreeNode<T>*) x->left), height((AvlTreeNode<T>*) x->right)) + 1;
        if (abs(height((AvlTreeNode<T>*) x->left) - height((AvlTreeNode<T>*) x->right)) == 2){
            if (dir1 == LEFT){
                if (dir2 == LEFT){
                    t = rotateLeft(x);
                } else {
                    t = doubleRotateLeft(x);
                }
            } else {
                if (dir2 == LEFT){
                    t = doubleRotateRight(x);
                } else {
                    t = rotateRight(x);
                }
            }
            y = c.pop();
            this->insertChild(y, t);
            break;
        }
    }
}

template<class T> void AvlTree<T>::insert(const T& item) {
    insert(new AvlTreeNode<T>(item));
}

#endif //DATASTRUCTURE_AVLTREE_H
