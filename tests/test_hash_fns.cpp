#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "HashFunctions.h"
#include <iostream>

using std::vector;

// testing non-crypto hashes, might add murmur3 (bitcoin implementation)
uint32_t lower_alphabet_fnv1a_32 = 0xb0bc0c82;
uint32_t lower_alphabet_fnv_32 = 0x819dafd8;

uint32_t hello_fnv1a_32 = 0x4f9f2cab;
uint32_t hello_fnv_32 = 0xb6fa7167;

TEST_CASE("FNV1A, FNV on 'hello'", "[hash]") 
{
    vector<uint8_t> s = {'h', 'e', 'l', 'l', 'o'};
    std::cout << "String: ";
    for (auto c : s) 
        if (c != 'o') 
            std::cout << c;
        else
            std::cout << c << "\n";

    REQUIRE(fnv1a(s) == hello_fnv1a_32);
    REQUIRE(fnv(s) == hello_fnv_32);
}

TEST_CASE("FNV1A, FNV on the lowercase alphabet", "[hash]")
{
    vector<uint8_t> lower_alphabet;
    std::cout << "String: ";
    for (int i = 97; i <=122; i++) {
        lower_alphabet.push_back(static_cast<uint8_t>(i));
    }

    for (auto c : lower_alphabet) {
        if (c != 'z') 
            std::cout << c;
        else 
            std::cout << c << "\n";
    }


    REQUIRE(fnv1a(lower_alphabet) == lower_alphabet_fnv1a_32);
    REQUIRE(fnv(lower_alphabet) == lower_alphabet_fnv_32);
}
