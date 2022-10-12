cmake_minimum_required(VERSION 3.12.3)
project(DataStructure)

set(CMAKE_CXX_STANDARD 20)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Test src/CounterHashMap.h src/Cache/CacheNode.h src/Cache/CacheLinkedList.h src/Cache/LRUCache.h src/Graph/Node.h src/Graph/Edge.h src/Graph/Graph.h src/Graph/SingleSourceShortestPath.h src/Graph/AllPairsShortestPath.h Test/catch.hpp Test/LRUCacheTest.cpp Test/CounterHashMapTest.cpp src/Stack.h src/Tree/TreeNode.h src/Tree/Tree.h Test/TreeTest.cpp src/Tree/AvlTreeNode.h src/Tree/AvlTree.h src/Tree/BTreeNode.h src/Tree/BTree.h src/Heap/HeapNode.h src/Heap/Heap.h src/Heap/MaxHeap.h src/Heap/MinHeap.h Test/HeapTest.cpp)