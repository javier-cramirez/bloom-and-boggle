#include "Bloom.h"
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <iostream>
#include <random>

TEST_CASE("BloomFilter, basic membership", "[bloom]") {
    constexpr uint32_t SEED = 12345;    
    BloomFilter bf(1000, 0.01, SEED);

    auto alice = std::vector<uint8_t>{'a', 'l', 'i', 'c', 'e'};
    auto bob = std::vector<uint8_t>{'b', 'o', 'b'};
    auto carol = std::vector<uint8_t>{'c', 'a', 'r', 'o', 'l'};

    SECTION("Inserted items could be in set") {
        bf.insert(alice);
        bf.insert(bob);
        REQUIRE(bf.contains(alice));
        REQUIRE(bf.contains(bob));
    }

    SECTION("Non-inserted items (with high p) not in set") {
        const int n = 100;
        int fp = 0;
        for (int i = 0; i < n; i++) 
            if (bf.contains(carol)) 
                fp++;
        REQUIRE (fp < 5); 
    }
} 

