//
// Created by Olcay Taner Yıldız on 29.10.2018.
//

#include "Node.h"

/**
 * A constructor of Node class which takes a T type input Label and assigns this Label to private variable
 * label.
 *
 * @param Label T type input.
 */
template<class T> Node<T>::Node(T Label) {
    this->label = label;
}

/**
 * Getter for the label.
 *
 * @return label.
 */
template<class T> T Node<T>::getLabel() {
    return label;
}

/**
 * The overridden toString method returns label as string.
 *
 * @return label string.
 */
template<class T> string Node<T>::to_string() {
    return label.to_string();
}
