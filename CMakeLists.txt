cmake_minimum_required(VERSION 3.12.3)
project(DataStructure)

set(CMAKE_CXX_STANDARD 17)

add_library(DataStructure CounterHashMap.h Cache/CacheNode.h Cache/CacheLinkedList.h Cache/LRUCache.h Graph/Node.h Graph/Edge.h Graph/Graph.h Graph/SingleSourceShortestPath.h Graph/AllPairsShortestPath.h)

add_executable(Test CounterHashMap.h Cache/CacheNode.h Cache/CacheLinkedList.h Cache/LRUCache.h Graph/Node.h Graph/Edge.h Graph/Graph.h Graph/SingleSourceShortestPath.h Graph/AllPairsShortestPath.h Test/catch.hpp Test/LRUCacheTest.cpp Test/CounterHashMapTest.cpp)