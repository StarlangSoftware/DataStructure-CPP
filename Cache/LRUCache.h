//
// Created by Olcay Taner Yıldız on 29.10.2018.
//

#ifndef DATASTRUCTURE_LRUCACHE_H
#define DATASTRUCTURE_LRUCACHE_H
#include <map>
#include "CacheNode.h"
#include "CacheLinkedList.h"
using namespace std;

template<class K, class T> class LRUCache {
private:
    int cacheSize;
    map<K, CacheNode<K, T>*> map;
    CacheLinkedList<K, T> cache;
public:
    LRUCache(int cacheSize);
    bool contains(K key);
    T get(K key);
    void add(K key, T data);
};

#endif //DATASTRUCTURE_LRUCACHE_H
