//
// Created by Olcay Taner YILDIZ on 19.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../Cache/LRUCache.h"

TEST_CASE("LRUCache-test1") {
    LRUCache<string, string> cache = LRUCache<string, string>(50);
    cache.add("item1", "1");
    cache.add("item2", "2");
    cache.add("item3", "3");
    REQUIRE_FALSE(!cache.contains("item2"));
    REQUIRE_FALSE(cache.contains("item4"));
}

TEST_CASE("LRUCache-test2") {
    LRUCache<string, string> cache = LRUCache<string, string>(5);
    cache.add("item1", "1");
    cache.add("item2", "2");
    cache.add("item3", "3");
    REQUIRE_FALSE(!cache.contains("item2"));
    REQUIRE_FALSE(!cache.contains("item1"));
}

TEST_CASE("LRUCache-test3") {
    LRUCache<int, int> cache = LRUCache<int, int>(10000);
    for (int i = 0; i < 10000; i++){
        cache.add(i, i);
    }
    for (int i = 0; i < 1000; i++){
        REQUIRE_FALSE(!cache.contains(random() %10000));
    }
}

TEST_CASE("LRUCache-test4") {
    LRUCache<int, int> cache = LRUCache<int, int>(1000000);
    for (int i = 0; i < 1000000; i++){
        cache.add(random() %1000000, i);
    }
    int count = 0;
    for (int i = 0; i < 1000000; i++){
        if (cache.contains(i)){
            count++;
        }
    }
    REQUIRE_THAT(count / 1000000.0, Catch::Matchers::WithinAbs(0.632, 0.001));
}

TEST_CASE("LRUCache-test5") {
    int size = 100000;
    LRUCache<int, int> cache = LRUCache<int, int>(size);
    for (int i = 0; i < size; i++){
        cache.add(i, i);
    }
    for (int j = 0; j < 100; j++) {
        auto start = std::chrono::system_clock::now();
        for (int i = 0; i < size; i++) {
            int data = random() % size + size;
            cache.add(data, data);
        }
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << 1000 * elapsed_seconds.count() << "\n";
    }
}
