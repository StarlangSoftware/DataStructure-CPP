//
// Created by Olcay Taner Yıldız on 29.10.2018.
//

#ifndef DATASTRUCTURE_EDGE_H
#define DATASTRUCTURE_EDGE_H


#include "Node.h"

template <class T> class Edge {
private:
    Node<T> from;
    Node<T> to;
    double weight;
public:
    Edge(const Node<T>& from, const Node<T>& to, double weight);
    Node<T> getTo() const;
    Node<T> getFrom() const;
    double getWeight() const;
};

/**
 * A constructor of {@link Edge} class which takes 3 inputs and initializes variables with these inputs.
 *
 * @param from   starting node of the edge.
 * @param to     ending node of the edge.
 * @param weight of the edge.
 */
template<class T> Edge<T>::Edge(const Node<T>& from, const Node<T>& to, double weight) {
    this->from = from;
    this->to = to;
    this->weight = weight;
}

/**
 * Getter for to {@link Node}.
 *
 * @return to {@link Node}.
 */
template<class T> Node<T> Edge<T>::getTo() const{
    return to;
}

/**
 * Getter for from {@link Node}.
 *
 * @return from {@link Node}.
 */
template<class T> Node<T> Edge<T>::getFrom() const{
    return from;
}

/**
 * Getter for weight.
 *
 * @return weight value.
 */
template<class T> double Edge<T>::getWeight() const{
    return weight;
}

#endif //DATASTRUCTURE_EDGE_H
