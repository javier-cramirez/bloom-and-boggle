#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H
#include <vector>
#include <cstdint>
#include "Murmur3Hash.h"

const uint32_t Prime = 0x01000193; // 16777619
const uint32_t Seed = 0x811C9DC5; // 2166136261

inline uint32_t fnvla(const std::vector<uint8_t>& data, uint32_t hash = Seed) 
{
    assert(data.size());
    uint64_t h = Seed ^ hash;
    for (auto b : data) {
        h ^= b;
        h *= Prime;
    }
}


#endif
