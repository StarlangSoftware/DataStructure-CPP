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
    AllPairsShortestPath(const unordered_set<Node<T>>& nodeList);
    void put(Node<T> fromNode, SingleSourceShortestPath<T> singleSourceShortestPath);
    void update(Node<T> fromNode, Node<T> toNode, double newLength, Node<T> newPrevious);
    double getLength(Node<T> fromNode, Node<T> toNode);
    vector<Node<T>> shortestPath(Node<T> fromNode, Node<T> toNode);
};

/**
 * A constructor of {@link AllPairsShortestPath} class which takes a {@link unordered_set} nodeList as input. It creates a new
 * {@link map} as paths. Then, loops through the nodeList and puts each node with its {@link SingleSourceShortestPath}
 * to paths {@link map}.
 *
 * @param nodeList {@link unordered_set} type nodeList.
 */
template<class T> AllPairsShortestPath<T>::AllPairsShortestPath(const unordered_set<Node<T>>& nodeList) {
    for (Node<T> node : nodeList) {
        paths.insert_or_assign(node, SingleSourceShortestPath<T>(node));
    }
}

/**
 * The put method takes a {@link Node} and a {@link SingleSourceShortestPath} as inputs and puts them into paths {@link map}.
 *
 * @param fromNode                 {@link Node} type input to put paths {@link map}.
 * @param singleSourceShortestPath {@link SingleSourceShortestPath} type input to put paths {@link map}.
 */
template<class T> void AllPairsShortestPath<T>::put(Node<T> fromNode, SingleSourceShortestPath<T> singleSourceShortestPath) {
    paths.insert_or_assign(fromNode, singleSourceShortestPath);
}

/**
 * The update method takes 3 {@link Node}s; fromNode,toNode and newPrevious, and a newLength as inputs. Then, gets the value of fromNode
 * from paths {@link map} and calls update method for that value in order to put toNode with newPrevious and newLength
 * into pathLength and previous {@link map}s.
 *
 * @param fromNode    {@link Node} type input.
 * @param toNode      {@link Node} type input.
 * @param newLength   length of the path.
 * @param newPrevious {@link Node} type input.
 */
template<class T> void AllPairsShortestPath<T>::update(Node<T> fromNode, Node<T> toNode, double newLength, Node<T> newPrevious) {
    paths.find(fromNode)->second.update(toNode, newLength, newPrevious);
}

/**
 * The getLength method takes two {@link Node}s as inputs; fromNode and toNode. It gets the value of fromNode from paths
 * {@link map} and returns the path length between fromNode and toNode.
 *
 * @param fromNode {@link Node} type input.
 * @param toNode   Node to check for the length.
 * @return length of the given path.
 */
template<class T> double AllPairsShortestPath<T>::getLength(Node<T> fromNode, Node<T> toNode) {
    return paths.find(fromNode)->second.getLength(toNode);
}

/**
 * The shortestPath method returns the path between fromNode and toNode as an {@link vector}.
 *
 * @param fromNode {@link Node} type input.
 * @param toNode   {@link Node} type input.
 * @return the path between fromNode and toNode as an {@link vector}.
 */
template<class T> vector<Node<T>> AllPairsShortestPath<T>::shortestPath(Node<T> fromNode, Node<T> toNode) {
    return paths.find(fromNode)->second.shortestPath(toNode);
}

#endif //DATASTRUCTURE_ALLPAIRSSHORTESTPATH_H
