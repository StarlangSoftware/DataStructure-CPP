//
// Created by Olcay Taner YILDIZ on 30/10/2018.
//

#ifndef DATASTRUCTURE_GRAPH_H
#define DATASTRUCTURE_GRAPH_H

#include <map>
#include <unordered_set>
#include "Node.h"
#include "Edge.h"
using namespace std;

template <class T> class Graph {
private:
    map<Node<T>, vector<Edge<T>>> edges;
    map<Node<T>, vector<Edge<T>>> fromEdges;
    unordered_set<Node<T>> nodes;
    bool directed = true;
    void addEdgeToEdgeList(map<Node<T>, vector<Edge<T>>> edgeMap, Node<T> node, Edge<T> newEdge);
    void addToEdges(Node<T> fromNode, Node<T> toNode, double weight);
public:
    Graph(bool directed);
};

#endif //DATASTRUCTURE_GRAPH_H
