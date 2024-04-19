//
// Created by Olcay Taner YILDIZ on 28.06.2022.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <vector>

using namespace std;

/**
 * Stack is a list data structure consisting of many elements. There are two types of operations defined for the
 * elements of the stack: Adding an element to the stack (push) and removing an element from the stack (pop). In a
 * stack, to be popped element is always the last pushed element. Also, when an element is pushed on to the stack, it
 * is placed on top of the stack (at the end of the list).
 * @param <T> Type of the data stored in the heap node.
 */
template <class K> class Stack{
private:
    vector<K> list;
public:
    Stack();
    void push(const K& item);
    K pop();
    bool isEmpty() const;
};

template<class K> Stack<K>::Stack() = default;

/**
 * When we push an element on top of the stack, we only need to increase the field top by 1 and place the new
 * element on this new position. If the stack is full before this push operation, we can not push.
 * @param item Item to insert.
 */
template<class K> void Stack<K>::push(const K& item) {
    list.push_back(item);
}

/**
 * When we remove an element from the stack (the function also returns that removed element), we need to be careful
 * if the stack was empty or not. If the stack is not empty, the topmost element of the stack is returned and the
 * field top is decreased by 1. If the stack is empty, the function will return null.
 * @return The removed element
 */
template<class K> K Stack<K>::pop() {
    if (!list.empty()){
        K item = list[list.size() - 1];
        list.pop_back();
        return item;
    } else {
        return nullptr;
    }
}

/**
 * The function checks whether an array-implemented stack is empty or not. The function returns true if the stack is
 * empty, false otherwise.
 * @return True if the stack is empty, false otherwise.
 */
template<class K> bool Stack<K>::isEmpty() const{
    return list.empty();
}

#endif //DATASTRUCTURE_STACK_H
