//
// Created by Olcay Taner Yıldız on 29.10.2018.
//

#ifndef DATASTRUCTURE_CACHENODE_H
#define DATASTRUCTURE_CACHENODE_H

template<class K, class T> class CacheNode {
private:
    T data;
    K key;
    CacheNode<K, T>* previous = nullptr;
    CacheNode<K, T>* next = nullptr;
public:
    CacheNode(K key, T data);
    T getData();
    K getKey();
    CacheNode<K, T>* getPrevious();
    CacheNode<K, T>* getNext();
    void setPrevious(CacheNode<K, T>* previous);
    void setNext(CacheNode<K, T>* next);
};

#endif //DATASTRUCTURE_CACHENODE_H
