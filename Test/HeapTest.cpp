//
// Created by Olcay Taner YILDIZ on 12.10.2022.
//

#include "catch.hpp"
#include "../src/Heap/MaxHeap.h"
#include "../src/Heap/MinHeap.h"
using namespace std;

int isSmallerHeap(const int& first, const int& second){
    return first - second;
}

int isSmallerHeapString(const string& first, const string& second){
    if (first < second){
        return -1;
    } else {
        if (first > second){
            return 1;
        } else {
            return 0;
        }
    }
}

TEST_CASE("HeapTest-testMaxHeap") {
    MaxHeap<int> maxHeap = MaxHeap<int>(8, isSmallerHeap);
    maxHeap.insert(4);
    maxHeap.insert(6);
    maxHeap.insert(2);
    maxHeap.insert(5);
    maxHeap.insert(3);
    maxHeap.insert(1);
    maxHeap.insert(7);
    int maxItem = maxHeap.deleteTop();
    REQUIRE(7 == maxItem);
    maxItem = maxHeap.deleteTop();
    REQUIRE(6 == maxItem);
    maxItem = maxHeap.deleteTop();
    REQUIRE(5 == maxItem);
}

TEST_CASE("HeapTest-testMaxHeapString") {
    MaxHeap<string> maxHeap = MaxHeap<string>(8, isSmallerHeapString);
    maxHeap.insert("d");
    maxHeap.insert("f");
    maxHeap.insert("b");
    maxHeap.insert("e");
    maxHeap.insert("c");
    maxHeap.insert("a");
    maxHeap.insert("g");
    string maxItem = maxHeap.deleteTop();
    REQUIRE("g" == maxItem);
    maxItem = maxHeap.deleteTop();
    REQUIRE("f" == maxItem);
    maxItem = maxHeap.deleteTop();
    REQUIRE("e" == maxItem);
}

TEST_CASE("HeapTest-testMinHeap") {
    MinHeap<int> minHeap = MinHeap<int>(8, isSmallerHeap);
    minHeap.insert(4);
    minHeap.insert(6);
    minHeap.insert(2);
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(1);
    minHeap.insert(7);
    int minItem = minHeap.deleteTop();
    REQUIRE(1 == minItem);
    minItem = minHeap.deleteTop();
    REQUIRE(2 == minItem);
    minItem = minHeap.deleteTop();
    REQUIRE(3 == minItem);
}

TEST_CASE("HeapTest-testMinHeapString") {
    MinHeap<string> minHeap = MinHeap<string>(8, isSmallerHeapString);
    minHeap.insert("d");
    minHeap.insert("f");
    minHeap.insert("b");
    minHeap.insert("e");
    minHeap.insert("c");
    minHeap.insert("a");
    minHeap.insert("g");
    string maxItem = minHeap.deleteTop();
    REQUIRE("a" == maxItem);
    maxItem = minHeap.deleteTop();
    REQUIRE("b" == maxItem);
    maxItem = minHeap.deleteTop();
    REQUIRE("c" == maxItem);
}
