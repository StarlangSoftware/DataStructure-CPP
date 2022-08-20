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

/**
 * A constructor of {@link SingleSourceShortestPath} class which takes a {@link Node} type input startNode. Assigns given startNode to startNode variable. Then,
 * calls update method in order to put startNode into pathLength and previous {@link map}s.
 *
 * @param startNode {@link Node} type input.
 */
template<class T> SingleSourceShortestPath<T>::SingleSourceShortestPath(Node<T> startNode) {
    this->startNode = startNode;
    update(startNode, 0, startNode);
}

/**
 * The update method takes 2 {@link Node}s; toNode and newPrevious, and a length value. Then it puts Node toNode with newLength
 * value into pathLength {@link map} and also the toNode and newPrevious nodes into previous {@link map}.
 *
 * @param toNode      {@link Node} type input.
 * @param newLength   length of the path.
 * @param newPrevious {@link Node} type input.
 */
template<class T> void SingleSourceShortestPath<T>::update(Node<T> toNode, double newLength, Node<T> newPrevious) {
    pathLength.insert_or_assign(toNode, newLength);
    previous.insert_or_assign(toNode, newPrevious);
}

/**
 * The getLength method takes a {@link Node} as input. If the pathLength {@link map} contains given Node, then it
 * returns the corresponding path length of that Node, if pathLength does not contain the given Node then its length will be
 * assigned as the DBL_MAX.
 *
 * @param toNode Node to check for the length.
 * @return length of the given path.
 */
template<class T> double SingleSourceShortestPath<T>::getLength(Node<T> toNode) {
    if (pathLength.contains(toNode)) {
        return pathLength.get(toNode);
    } else {
        return DBL_MAX;
    }
}

/**
 * The shortestPath method takes a {@link Node} toNode as input which is the destination node. First it creates a new
 * {@link vector} result and assigns given toNode to previousNode and adds it to the newly created {@link vector}.
 * While the previousNode is not equal to the startNode, starting from toNodes' previousNode it tries to reach the startNode
 * and adds each previousNode to the new {@link vector} result.
 *
 * @param toNode {@link Node} type input represents destination node.
 * @return vector that contains path from destination to source.
 */
template<class T> vector<Node<T>> SingleSourceShortestPath<T>::shortestPath(Node<T> toNode) {
    Node<T> previousNode;
    vector<Node<T>> result;
    previousNode = toNode;
    result.push_back(previousNode);
    while (previousNode != startNode) {
        previousNode = previous.find(previousNode)->second;
        result.push_back(previousNode);
    }
    return result;
}

#endif //DATASTRUCTURE_SINGLESHORTESTPATH_H
