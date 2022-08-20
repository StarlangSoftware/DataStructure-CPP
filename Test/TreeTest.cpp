//
// Created by Olcay Taner YILDIZ on 30.06.2022.
//

#include "catch.hpp"
#include "../src/Tree/Tree.h"
#include "../src/Tree/AvlTree.h"
#include "../src/Tree/BTree.h"

int isSmaller(int first, int second){
    return first - second;
}

TEST_CASE("TreeTest-testTree") {
    Tree<int> tree = Tree<int>(isSmaller);
    tree.insert(4);
    tree.insert(6);
    tree.insert(2);
    tree.insert(5);
    tree.insert(3);
    tree.insert(1);
    tree.insert(7);
    REQUIRE(tree.search(3) != nullptr);
    REQUIRE(tree.search(8) == nullptr);
}

TEST_CASE("TreeTest-testTree2") {
    AvlTree<int> tree = AvlTree<int>(isSmaller);
    for (int i = 1; i <= 31; i++){
        tree.insert(i);
    }
    for (int i = 1; i <= 31; i++){
        REQUIRE(tree.search(i) != nullptr);
    }
    REQUIRE(tree.search(32) == nullptr);
}

TEST_CASE("TreeTest-testTree3") {
    BTree<int> tree = BTree<int>(1, isSmaller);
    for (int i = 1; i <= 31; i++){
        tree.insert(i);
    }
    for (int i = 1; i <= 31; i++){
        REQUIRE(tree.search(i) != nullptr);
    }
    REQUIRE(tree.search(32) == nullptr);
}
