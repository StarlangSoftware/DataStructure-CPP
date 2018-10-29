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
    Edge(Node<T> from, Node<T> to, double weight);
    Node<T> getTo();
    Node<T> getFrom();
    double getWeight();
};

#endif //DATASTRUCTURE_EDGE_H
