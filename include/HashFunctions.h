#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H
#include <vector>
#include <cstdint>
#include "Murmur3Hash.h"

const uint32_t Prime = 1099511628211ULL;

inline uint64_t fnvla(uint32_t seed, const std::vector<uint8_t>& data) 
{
    assert(data.size());
    uint64_t h = 146527u ^ seed;
    for (auto b : data) {
        h ^= b;
        h *= Prime;
    }
}


#endif
