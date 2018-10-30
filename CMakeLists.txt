cmake_minimum_required(VERSION 3.12)
project(DataStructure)

set(CMAKE_CXX_STANDARD 20)

add_library(DataStructure CounterHashMap.cpp CounterHashMap.h Cache/CacheNode.cpp Cache/CacheNode.h Cache/CacheLinkedList.cpp Cache/CacheLinkedList.h Cache/LRUCache.cpp Cache/LRUCache.h Graph/Node.cpp Graph/Node.h Graph/Edge.cpp Graph/Edge.h Graph/Graph.cpp Graph/Graph.h)