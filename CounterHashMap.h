//
// Created by Olcay Taner YILDIZ on 24/10/2018.
//

#ifndef DATASTRUCTURE_COUNTERHASHMAP_H
#define DATASTRUCTURE_COUNTERHASHMAP_H

#include <map>
using namespace std;

template <class K> class CounterHashMap : public map<K, int> {
public:
    CounterHashMap();
    void put(K key);
};


#endif //DATASTRUCTURE_COUNTERHASHMAP_H
