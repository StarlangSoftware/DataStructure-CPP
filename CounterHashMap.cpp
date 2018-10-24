//
// Created by Olcay Taner YILDIZ on 24/10/2018.
//
#include <map>
#include "CounterHashMap.h"

/**
 * A constructor which calls its super.
 */
template<class K> CounterHashMap<K>::CounterHashMap() {
}

/**
 * The put method takes a K type input. If this map contains a mapping for the key, it puts this key after
 * incrementing its value by one. If his map does not contain a mapping, then it directly puts key with the value of 1.
 *
 * @param key to put.
 */
template<class K> void CounterHashMap<K>::put(K key) {
    if (find(key) != this->end()) {
        emplace(key, find(key)->second + 1);
    } else {
        emplace(key, 1);
    }
}
