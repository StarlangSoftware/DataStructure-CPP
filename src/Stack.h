//
// Created by Olcay Taner YILDIZ on 28.06.2022.
//

#ifndef DATASTRUCTURE_STACK_H
#define DATASTRUCTURE_STACK_H

#include <vector>

using namespace std;

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

template<class K> void Stack<K>::push(const K& item) {
    list.push_back(item);
}

template<class K> K Stack<K>::pop() {
    if (!list.empty()){
        K item = list[list.size() - 1];
        list.pop_back();
        return item;
    } else {
        return nullptr;
    }
}

template<class K> bool Stack<K>::isEmpty() const{
    return list.empty();
}

#endif //DATASTRUCTURE_STACK_H
