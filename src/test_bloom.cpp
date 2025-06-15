#include "BloomFilter.h"
#include <iostream>
#include <random>

int main() {
    // ~5000 items, 0.5% false positives
    BloomFilter bf(5000, 0.005, std::random_device{}());

    // Example keys as byte-vectors:
    std::vector<uint8_t> alice{ 'a','l','i','c','e' };
    std::vector<uint8_t> bob  { 'b','o','b'   };

    bf.insert(alice);
    bf.insert(bob);

    for (auto name : { alice, bob, std::vector<uint8_t>{'c','a','r','o','l'} }) {
        bool maybe = bf.contains(name);
        std::cout << (maybe ? "maybe in set\n" : "definitely not\n");
    }
}
