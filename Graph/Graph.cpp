//
// Created by Olcay Taner YILDIZ on 30/10/2018.
//

#include "Graph.h"

/**
 * A constructor of {@link Graph} class which takes a boolean directed as input. Creates a {@link map} for edges
 * and fromEdges, a {@link unordered_set} for nodes and assigns directed value to directed variable.
 *
 * @param directed boolean input.
 */
template<class T> Graph<T>::Graph(bool directed) {
    this->directed = directed;
}

/**
 * The addEdgeToEdgeList method takes a {@link map}, a {@link Node} and an {@link Edge} as inputs. If given
 * {@link vector} contains given {@link Node}, it adds value of given {@link Node} at {@link map} to given
 * {@link vector}. If not, it creates a new {@link vector} as edgeList and adds given {@link Edge} to newly
 * created {@link vector} and also puts to the given {@link vector}.
 *
 * @param edgeMap {@link map} type input.
 * @param node    {@link Node} type input.
 * @param newEdge {@link Edge} to add {@link vector}.
 */
template<class T> void Graph<T>::addEdgeToEdgeList(map<Node<T>, vector<Edge<T>>> edgeMap, Node<T> node, Edge<T> newEdge) {
    vector<Edge<T>> edgeList;
    if (edgeMap.contains(node)) {
        edgeList = edgeMap.find(node)->second;
        edgeList.push_back(newEdge);
    } else {
        edgeList.push_back(newEdge);
        edgeMap.emplace(node, edgeList);
    }
}

/**
 * The addToEdges method takes 2 {@link Node}s as inputs; fromNode and toNode and also the corresponding weight of the edge
 * between these two nodes. First, if given fromNode or toNode are not listed in nodes {@link set}, it adds these nodes to
 * nodes {@link set}. If they are listed, then it creates a new {@link Edge} between fromNode and toNode with given weight
 * and calls addEdgeToEdgeList method for adding newEdge to edges and fromEdges {@link set}s.
 *
 * @param fromNode Node that starting an edge.
 * @param toNode   Node that ending an edge.
 * @param weight   between two nodes.
 */
template<class T> void Graph<T>::addToEdges(Node<T> fromNode, Node<T> toNode, double weight) {
    Edge<T> newEdge;
    if (!nodes.contains(fromNode)) {
        nodes.insert(fromNode);
    }
    if (!nodes.contains(toNode)) {
        nodes.insert(toNode);
    }
    newEdge(fromNode, toNode, weight);
    addEdgeToEdgeList(edges, fromNode, newEdge);
    addEdgeToEdgeList(fromEdges, toNode, newEdge);
}

/**
 * The addEdge method takes 2 {@link Node}s as inputs; fromNode and toNode and also the corresponding weight of the edge
 * between these two nodes. It calls addToEdges method to create an edge between fromNode and toNode and if the graph
 * is not directed it also calls addToEdges method to create a back edge between these nodes.
 *
 * @param fromNode Node that starting an edge.
 * @param toNode   Node that ending an edge.
 * @param weight   between two nodes.
 */
template<class T> void Graph<T>::addEdge(Node<T> fromNode, Node<T> toNode, double weight) {
    addToEdges(fromNode, toNode, weight);
    if (!directed) {
        addToEdges(toNode, fromNode, weight);
    }
}

/**
 * The containsEdge method takes two {@link Node}s as inputs; fromNode and toNode. If edges {@link map} contains
 * fromNode it loops through the edges and if the label of current toNode equals to the given toNode's label then it returns true,
 * false otherwise.
 *
 * @param fromNode {@link Node} used to search for keys.
 * @param toNode   {@link Node} used to search for labels.
 * @return true if the label of to Node equals to the toNode's label, false otherwise.
 */
template<class T> bool Graph<T>::containsEdge(Node<T> fromNode, Node<T> toNode) {
    if (edges.contains(fromNode)) {
        for (Edge<T> edge : edges.find(fromNode)->second) {
            if (edge.to().getLabel() == toNode.getLabel()) {
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

/**
 * The numberOfNodes method returns the size of the nodes {@link set}.
 *
 * @return the size of the nodes {@link set}.
 */
template<class T> unsigned long Graph<T>::numberOfNodes() {
    return nodes.size();
}

/**
 * The numberOfEdges method loops through edges {@link map} and accumulates the size of edges {@link set} of each node.
 *
 * @return sum of the total edges of nodes.
 */
template<class T> unsigned long Graph<T>::numberOfEdges() {
    unsigned long sum = 0;
    for (auto const& node : edges) {
        sum += node.second.size();
    }
    return sum;
}

/**
 * The nodeList method returns the nodes {@link Set}.
 *
 * @return the nodes {@link Set}.
 */
template<class T> unordered_set<Node<T>> Graph<T>::nodeList() {
    return nodes;
}
