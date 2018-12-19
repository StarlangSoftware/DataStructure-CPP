cmake_minimum_required(VERSION 3.12)
project(DataStructure)

set(CMAKE_CXX_STANDARD 20)

add_library(DataStructure CounterHashMap.h Cache/CacheNode.h Cache/CacheLinkedList.h Cache/LRUCache.h Graph/Node.h Graph/Edge.h Graph/Graph.h Graph/SingleSourceShortestPath.h Graph/AllPairsShortestPath.h)