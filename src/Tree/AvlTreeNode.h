//
// Created by Olcay Taner YILDIZ on 30.06.2022.
//

#ifndef DATASTRUCTURE_AVLTREENODE_H
#define DATASTRUCTURE_AVLTREENODE_H

#include "TreeNode.h"

template <class T> class AvlTreeNode : public TreeNode<T>{
public:
    int height;
    explicit AvlTreeNode(T data);
};

template<class T>
AvlTreeNode<T>::AvlTreeNode(T data):TreeNode<T>(data) {
    height = 1;
}

#endif //DATASTRUCTURE_AVLTREENODE_H
