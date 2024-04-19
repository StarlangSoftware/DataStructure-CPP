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
    T getData() const;
    HeapNode();
};

/**
 * Constructor of HeapNode.
 * @param data Data to be stored in the heap node.
 */
template<class T> HeapNode<T>::HeapNode(const T& data) {
    this->data = data;
}

/**
 * Mutator of the data field
 * @return Data
 */
template<class T> T HeapNode<T>::getData() const{
    return data;
}

template<class T> HeapNode<T>::HeapNode() = default;


#endif //DATASTRUCTURE_HEAPNODE_H
