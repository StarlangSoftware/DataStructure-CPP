//
// Created by Olcay Taner Yıldız on 29.10.2018.
//

#ifndef DATASTRUCTURE_NODE_H
#define DATASTRUCTURE_NODE_H

#include <string>
using namespace std;

template <class T> class Node {
private:
    T label;
public:
    Node(const T& Label);
    T getLabel() const;
    string to_string() const;
};

/**
 * A constructor of Node class which takes a T type input Label and assigns this Label to private variable
 * label.
 *
 * @param Label T type input.
 */
template<class T> Node<T>::Node(const T& Label) {
    this->label = label;
}

/**
 * Getter for the label.
 *
 * @return label.
 */
template<class T> T Node<T>::getLabel() const{
    return label;
}

/**
 * The overridden toString method returns label as string.
 *
 * @return label string.
 */
template<class T> string Node<T>::to_string() const{
    return label.to_string();
}

#endif //DATASTRUCTURE_NODE_H
