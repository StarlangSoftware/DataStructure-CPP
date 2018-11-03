//
// Created by Olcay Taner Yıldız on 3.11.2018.
//

#ifndef DATASTRUCTURE_ALLPAIRSSHORTESTPATH_H
#define DATASTRUCTURE_ALLPAIRSSHORTESTPATH_H

#include <map>
#include <unordered_set>
#include "SingleSourceShortestPath.h"
#include "Node.h"

template <class T> class AllPairsShortestPath {
private:
    map<Node<T>, SingleSourceShortestPath<T>> paths;
public:
    AllPairsShortestPath(unordered_set<Node<T>> nodeList);
    void put(Node<T> fromNode, SingleSourceShortestPath<T> singleSourceShortestPath);
    void update(Node<T> fromNode, Node<T> toNode, double newLength, Node<T> newPrevious);
    double getLength(Node<T> fromNode, Node<T> toNode);
    vector<Node<T>> shortestPath(Node<T> fromNode, Node<T> toNode);
};

#endif //DATASTRUCTURE_ALLPAIRSSHORTESTPATH_H
