//
// Created by Olcay Taner YILDIZ on 12.10.2022.
//

#ifndef DATASTRUCTURE_MINHEAP_H
#define DATASTRUCTURE_MINHEAP_H

#include "Heap.h"

template <class T> class MinHeap : public Heap<T>{
public:
    using Heap<T>::comparator;
    typedef int(*ComparatorType)(T, T);
    explicit MinHeap(int N, ComparatorType comparator);
    int compare(T data1, T data2);
};

template<class T> MinHeap<T>::MinHeap(int N, MinHeap::ComparatorType comparator): Heap<T>(N, comparator) {
}

template<class T> int MinHeap<T>::compare(T data1, T data2) {
    return -comparator(data1, data2);
}

#endif //DATASTRUCTURE_MINHEAP_H
