//
// Created by Olcay Taner YILDIZ on 12.10.2022.
//

#ifndef DATASTRUCTURE_MAXHEAP_H
#define DATASTRUCTURE_MAXHEAP_H

#include "Heap.h"

template <class T> class MaxHeap : public Heap<T>{
public:
    using Heap<T>::comparator;
    typedef int(*ComparatorType)(const T&, const T&);
    explicit MaxHeap(int N, ComparatorType comparator);
    int compare(const T& data1, const T& data2);
};

template<class T> MaxHeap<T>::MaxHeap(int N, MaxHeap::ComparatorType comparator): Heap<T>(N, comparator) {
}

template<class T> int MaxHeap<T>::compare(const T& data1, const T& data2) {
    return comparator(data1, data2);
}

#endif //DATASTRUCTURE_MAXHEAP_H
