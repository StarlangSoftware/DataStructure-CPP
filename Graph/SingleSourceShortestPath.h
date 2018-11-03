//
// Created by Olcay Taner Yıldız on 3.11.2018.
//

#ifndef DATASTRUCTURE_SINGLESHORTESTPATH_H
#define DATASTRUCTURE_SINGLESHORTESTPATH_H

#include <map>
#include "Node.h"
using namespace std;

template <class T> class SingleSourceShortestPath {
private:
    map<Node<T>, double> pathLength;
    map<Node<T>, Node<T>> previous;
    Node<T> startNode;
public:
    explicit SingleSourceShortestPath(Node<T> startNode);
    void update(Node<T> toNode, double newLength, Node<T> newPrevious);
    double getLength(Node<T> toNode);
    vector<Node<T>> shortestPath(Node<T> toNode);
};

#endif //DATASTRUCTURE_SINGLESHORTESTPATH_H
