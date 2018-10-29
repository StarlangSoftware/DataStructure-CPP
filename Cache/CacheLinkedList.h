//
// Created by Olcay Taner Yıldız on 29.10.2018.
//

#ifndef DATASTRUCTURE_CACHELINKEDLIST_H
#define DATASTRUCTURE_CACHELINKEDLIST_H


#include "CacheNode.h"

template<class K, class T> class CacheLinkedList {
private:
    CacheNode<K, T>* head = nullptr;
    CacheNode<K, T>* tail = nullptr;
public:
    virtual ~CacheLinkedList();
    void remove(CacheNode<K, T>* cacheNode);
    void add(CacheNode<K, T>* cacheNode);
    CacheNode<K, T>* remove();
};

#endif //DATASTRUCTURE_CACHELINKEDLIST_H
