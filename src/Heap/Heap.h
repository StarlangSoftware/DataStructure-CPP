//
// Created by Olcay Taner YILDIZ on 12.10.2022.
//

#ifndef DATASTRUCTURE_HEAP_H
#define DATASTRUCTURE_HEAP_H

#include "HeapNode.h"

template <class T> class Heap{
protected:
    typedef int(*ComparatorType)(const T&, const T&);
    ComparatorType comparator;
private:
    HeapNode<T>* array;
    int count;
    int N{};
    void percolateDown(int no);
    void percolateUp(int no);
public:
    explicit Heap(int N, ComparatorType comparator);
    virtual int compare(const T& data1, const T& data2) = 0;
    bool isEmpty() const;
    void swapNode(int index1, int index2);
    void insert(const T& data);
    T deleteTop();
};

template<class T> Heap<T>::Heap(int N, Heap::ComparatorType comparator) {
    array = new HeapNode<T>[N];
    count = 0;
    this->N = N;
    this->comparator = comparator;
}

template<class T> bool Heap<T>::isEmpty() const{
    return count == 0;
}

template<class T> void Heap<T>::swapNode(int index1, int index2) {
    HeapNode<T> tmp = array[index1];
    array[index1] = array[index2];
    array[index2] = tmp;
}

template<class T> void Heap<T>::percolateDown(int no) {
    int left = 2 * no + 1;
    int right = 2 * no + 2;
    while ((left < count && compare(array[no].getData(), array[left].getData()) < 0) ||
           (right < count && compare(array[no].getData(), array[right].getData()) < 0)){
        if (right >= count || compare(array[left].getData(), array[right].getData()) > 0){
            swapNode(no, left);
            no = left;
        } else {
            swapNode(no, right);
            no = right;
        }
        left = 2 * no + 1;
        right = 2 * no + 2;
    }
}

template<class T> void Heap<T>::percolateUp(int no) {
    int parent = (no - 1) / 2;
    while (parent >= 0 && compare(array[parent].getData(), array[no].getData()) < 0){
        swapNode(parent, no);
        no = parent;
        parent = (no - 1) / 2;
    }
}

template<class T> T Heap<T>::deleteTop() {
    HeapNode<T> tmp;
    tmp = array[0];
    array[0] = array[count - 1];
    percolateDown(0);
    count--;
    return tmp.getData();
}

template<class T> void Heap<T>::insert(const T& data) {
    if (count < N){
        count++;
    }
    array[count - 1] = HeapNode<T>(data);
    percolateUp(count - 1);
}

#endif //DATASTRUCTURE_HEAP_H
