//
// Created by Olcay Taner YILDIZ on 29.06.2022.
//

#ifndef DATASTRUCTURE_TREENODE_H
#define DATASTRUCTURE_TREENODE_H

template <class T> class TreeNode{
public:
    T data;
    TreeNode<T>* left = nullptr;
    TreeNode<T>* right = nullptr;
    explicit TreeNode(const T& data);
    ~TreeNode();
};

template<class T> TreeNode<T>::TreeNode(const T& data) {
    this->data = data;
}

template<class T>
TreeNode<T>::~TreeNode() {
    delete left;
    delete right;
}

#endif //DATASTRUCTURE_TREENODE_H
