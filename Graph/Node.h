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
    Node(T Label);
    T getLabel();
    string to_string();
};

#endif //DATASTRUCTURE_NODE_H
