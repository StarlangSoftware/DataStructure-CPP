//
// Created by Olcay Taner YILDIZ on 12.10.2022.
//

#ifndef DATASTRUCTURE_HEAPNODE_H
#define DATASTRUCTURE_HEAPNODE_H


template <class T> class HeapNode {
private:
    T data;
public:
    explicit HeapNode(const T& data);
    T getData();
    HeapNode();
};

template<class T> HeapNode<T>::HeapNode(const T& data) {
    this->data = data;
}

template<class T> T HeapNode<T>::getData() {
    return data;
}

template<class T> HeapNode<T>::HeapNode() = default;


#endif //DATASTRUCTURE_HEAPNODE_H
