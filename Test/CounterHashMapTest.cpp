//
// Created by Olcay Taner YILDIZ on 19.12.2020.
//

#include "catch.hpp"
#include "../src/CounterHashMap.h"

TEST_CASE("CounterHashMap-testPut1") {
    CounterHashMap<string> counterHashMap = CounterHashMap<string>();
    counterHashMap.put("item1");
    counterHashMap.put("item2");
    counterHashMap.put("item3");
    counterHashMap.put("item1");
    counterHashMap.put("item2");
    counterHashMap.put("item1");
    REQUIRE(3 == counterHashMap.count("item1"));
    REQUIRE(2 == counterHashMap.count("item2"));
    REQUIRE(1 == counterHashMap.count("item3"));
}

TEST_CASE("CounterHashMap-testPut2") {
    CounterHashMap<int> counterHashMap = CounterHashMap<int>();
    for (int i = 0; i < 1000; i++){
        counterHashMap.put(random() %1000);
    }
    int count = 0;
    for (int i = 0; i < 1000; i++){
        count += counterHashMap.count(i);
    }
    REQUIRE(1000 == count);
}

TEST_CASE("CounterHashMap-testSumOfCounts") {
    CounterHashMap<int> counterHashMap = CounterHashMap<int>();
    for (int i = 0; i < 1000; i++){
        counterHashMap.put(random() % 1000);
    }
    REQUIRE(1000 == counterHashMap.sumOfCounts());
}

TEST_CASE("CounterHashMap-testPut3") {
    CounterHashMap<int> counterHashMap = CounterHashMap<int>();
    for (int i = 0; i < 1000000; i++){
        counterHashMap.put(random() % 1000000);
    }
    REQUIRE_THAT(counterHashMap.size() / 1000000.0, Catch::Matchers::WithinAbs(0.632, 0.001));
}

TEST_CASE("CounterHashMap-testPutNTimes1") {
    CounterHashMap<string> counterHashMap = CounterHashMap<string>();
    counterHashMap.putNTimes("item1", 2);
    counterHashMap.putNTimes("item2", 3);
    counterHashMap.putNTimes("item3", 6);
    counterHashMap.putNTimes("item1", 2);
    counterHashMap.putNTimes("item2", 3);
    counterHashMap.putNTimes("item1", 2);
    REQUIRE(6 == counterHashMap.count("item1"));
    REQUIRE(6 == counterHashMap.count("item2"));
    REQUIRE(6 == counterHashMap.count("item3"));
}

TEST_CASE("CounterHashMap-testPutNTimes2") {
    CounterHashMap<int> counterHashMap = CounterHashMap<int>();
    for (int i = 0; i < 1000; i++){
        counterHashMap.putNTimes(random() % 1000, i + 1);
    }
    REQUIRE(500500 == counterHashMap.sumOfCounts());
}

TEST_CASE("CounterHashMap-testMax") {
    CounterHashMap<string> counterHashMap = CounterHashMap<string>();
    counterHashMap.put("item1");
    counterHashMap.put("item2");
    counterHashMap.put("item3");
    counterHashMap.put("item1");
    counterHashMap.put("item2");
    counterHashMap.put("item1");
    REQUIRE("item1" == counterHashMap.max());
}

TEST_CASE("CounterHashMap-testMaxThreshold1") {
    CounterHashMap<string> counterHashMap = CounterHashMap<string>();
    counterHashMap.put("item1");
    counterHashMap.put("item2");
    counterHashMap.put("item3");
    counterHashMap.put("item1");
    counterHashMap.put("item2");
    counterHashMap.put("item1");
    REQUIRE("item1" == counterHashMap.max(0.4999));
    REQUIRE(counterHashMap.max(0.5001).empty());
}

TEST_CASE("CounterHashMap-testMaxThreshold2") {
    CounterHashMap<string> counterHashMap = CounterHashMap<string>();
    for (int i = 0; i < 1000000; i++){
        counterHashMap.put(to_string(random() % 100));
    }
    double probability = counterHashMap.count(counterHashMap.max()) / 1000000.0;
    REQUIRE(!counterHashMap.max(probability - 0.001).empty());
    REQUIRE(counterHashMap.max(probability + 0.001).empty());
}

TEST_CASE("CounterHashMap-testAdd1") {
    CounterHashMap<string> counterHashMap1 = CounterHashMap<string>();
    counterHashMap1.put("item1");
    counterHashMap1.put("item2");
    counterHashMap1.put("item3");
    counterHashMap1.put("item1");
    counterHashMap1.put("item2");
    counterHashMap1.put("item1");
    CounterHashMap<string> counterHashMap2 = CounterHashMap<string>();
    counterHashMap2.putNTimes("item1", 2);
    counterHashMap2.putNTimes("item2", 3);
    counterHashMap2.putNTimes("item3", 6);
    counterHashMap2.putNTimes("item1", 2);
    counterHashMap2.putNTimes("item2", 3);
    counterHashMap2.putNTimes("item1", 2);
    counterHashMap1.add(counterHashMap2);
    REQUIRE(9 == counterHashMap1.count("item1"));
    REQUIRE(8 == counterHashMap1.count("item2"));
    REQUIRE(7 == counterHashMap1.count("item3"));
}

TEST_CASE("CounterHashMap-testAdd2") {
    CounterHashMap<string> counterHashMap1 = CounterHashMap<string>();
    counterHashMap1.put("item1");
    counterHashMap1.put("item2");
    counterHashMap1.put("item1");
    counterHashMap1.put("item2");
    counterHashMap1.put("item1");
    CounterHashMap<string> counterHashMap2 =  CounterHashMap<string>();
    counterHashMap2.put("item4");
    counterHashMap2.putNTimes("item5", 4);
    counterHashMap2.put("item2");
    counterHashMap1.add(counterHashMap2);
    REQUIRE(3 == counterHashMap1.count("item1"));
    REQUIRE(3 == counterHashMap1.count("item2"));
    REQUIRE(1 == counterHashMap1.count("item4"));
    REQUIRE(4 == counterHashMap1.count("item5"));
}

TEST_CASE("CounterHashMap-testAdd3") {
    CounterHashMap<int> counterHashMap1 = CounterHashMap<int>();
    for (int i = 0; i < 1000; i++){
        counterHashMap1.put(i);
    }
    CounterHashMap<int> counterHashMap2 = CounterHashMap<int>();
    for (int i = 500; i < 1000; i++){
        counterHashMap2.putNTimes(1000 + i, i + 1);
    }
    counterHashMap1.add(counterHashMap2);
    REQUIRE(1500 == counterHashMap1.size());
}

TEST_CASE("CounterHashMap-testTopN1") {
    CounterHashMap<string> counterHashMap = CounterHashMap<string>();
    counterHashMap.put("item1");
    counterHashMap.put("item2");
    counterHashMap.put("item3");
    counterHashMap.put("item1");
    counterHashMap.put("item2");
    counterHashMap.put("item1");
    REQUIRE("item1" == counterHashMap.topN(1)[0].first);
    REQUIRE("item2" == counterHashMap.topN(2)[1].first);
    REQUIRE("item3" == counterHashMap.topN(3)[2].first);
}

TEST_CASE("CounterHashMap-testTopN2") {
    CounterHashMap<string> counterHashMap = CounterHashMap<string>();
    for (int i = 0; i < 1000; i++){
        counterHashMap.putNTimes(to_string(i), 2 * i + 2);
    }
    REQUIRE(to_string(990) == counterHashMap.topN(10)[9].first);
    REQUIRE(to_string(900) == counterHashMap.topN(100)[99].first);
}
