//
// Created by Olcay Taner YILDIZ on 30.06.2022.
//

#ifndef DATASTRUCTURE_BTREENODE_H
#define DATASTRUCTURE_BTREENODE_H

template <class T> class BTreeNode{
public:
    typedef int(*ComparatorType)(T, T);
    T* K;
    int m;
    int d;
    bool leaf;
    BTreeNode<T>** children;
    explicit BTreeNode(int d);
    BTreeNode(BTreeNode<T>* firstChild, BTreeNode<T>* secondChild, T newK, int d);
    ~BTreeNode();
    int position(const T& value, ComparatorType comparator) const;
    BTreeNode<T>* insertNode(const T& value, ComparatorType comparator, bool isRoot);
    BTreeNode<T>* insertLeaf(const T& value, ComparatorType comparator);
private:
    void insertIntoK(int index, const T& insertedK);
    void moveHalfOfTheKToNewNode(BTreeNode<T>* newNode);
    void moveHalfOfTheChildrenToNewNode(BTreeNode<T>* newNode);
    void moveHalfOfTheElementsToNewNode(BTreeNode<T>* newNode);
};

template<class T> BTreeNode<T>::BTreeNode(int d) {
    m = 0;
    this->d = d;
    leaf = true;
    K = new T[2 * d + 1];
    children = new BTreeNode<T>*[2 * d + 1];
}

template<class T> BTreeNode<T>::BTreeNode(BTreeNode<T> *firstChild, BTreeNode<T> *secondChild, T newK, int d) {
    this->d = d;
    K = new T[2 * d + 1];
    children = new BTreeNode<T>*[2 * d + 1];
    m = 1;
    leaf = false;
    children[0] = firstChild;
    children[1] = secondChild;
    K[0] = newK;
}

template<class T>
BTreeNode<T>::~BTreeNode() {
    delete K;
    for (int i = 0; i < 2 * d + 1; i++) {
        delete children[i];
    }
}

template<class T> int BTreeNode<T>::position(const T& value, ComparatorType comparator) const{
    if (m == 0){
        return 0;
    }
    if (comparator(value, K[m - 1]) > 0){
        return m;
    } else {
        for (int i = 0; i < m; i++){
            if (comparator(value, K[i]) <= 0){
                return i;
            }
        }
    }
    return -1;
}

template<class T> void BTreeNode<T>::insertIntoK(int index, const T& insertedK) {
    for (int i = m; i > index; i--){
        K[i] = K[i - 1];
    }
    K[index] = insertedK;
}

template<class T> void BTreeNode<T>::moveHalfOfTheKToNewNode(BTreeNode<T>* newNode) {
    for (int i = 0; i < d; i++) {
        newNode->K[i] = K[i + d + 1];
    }
    newNode->m = d;
}

template<class T> void BTreeNode<T>::moveHalfOfTheChildrenToNewNode(BTreeNode<T> *newNode) {
    for (int i = 0 ; i < d; i++){
        newNode->children[i] = children[i + d + 1];
        children[i + d + 1] = nullptr;
    }
}

template<class T> void BTreeNode<T>::moveHalfOfTheElementsToNewNode(BTreeNode *newNode) {
    moveHalfOfTheKToNewNode(newNode);
    moveHalfOfTheChildrenToNewNode(newNode);
}

template<class T> BTreeNode<T> *BTreeNode<T>::insertNode(const T& value, ComparatorType comparator, bool isRoot) {
    BTreeNode<T>* s;
    BTreeNode<T>* newNode;
    int child;
    child = position(value, comparator);
    if (!children[child]->leaf){
        s = children[child]->insertNode( value, comparator, false);
    } else {
        s = children[child]->insertLeaf(value, comparator);
    }
    if (s == nullptr){
        return nullptr;
    }
    insertIntoK(child, children[child]->K[d]);
    if (m < 2 * d){
        children[child + 1] = s;
        m++;
        return nullptr;
    } else {
        newNode = new BTreeNode<T>(d);
        newNode->leaf = false;
        moveHalfOfTheElementsToNewNode(newNode);
        newNode->children[d] = s;
        m = d;
        if (isRoot){
            auto* a = new BTreeNode<T>(this, newNode, this->K[d], d);
            return a;
        } else {
            return newNode;
        }
    }
}

template<class T> BTreeNode<T> *BTreeNode<T>::insertLeaf(const T& value, ComparatorType comparator) {
    int child;
    BTreeNode<T>* newNode;
    child = position(value, comparator);
    insertIntoK(child, value);
    if (m < 2 * d){
        m++;
        return nullptr;
    } else {
        newNode = new BTreeNode<T>(d);
        moveHalfOfTheKToNewNode(newNode);
        m = d;
        return newNode;
    }
}

#endif //DATASTRUCTURE_BTREENODE_H
