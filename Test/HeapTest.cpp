//
// Created by Olcay Taner YILDIZ on 12.10.2022.
//

#include "catch.hpp"
#include "../src/Heap/MaxHeap.h"
#include "../src/Heap/MinHeap.h"

int isSmallerHeap(int first, int second){
    return first - second;
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
