#ifndef HASH_FUNCTIONS_H
#define HASH_FUNCTIONS_H
#include <vector>
#include <cstdint>
#include <cassert>

static const uint32_t Prime = 0x01000193; // 16777619
static const uint32_t Seed = 0x811C9DC5; // 2166136261

inline uint32_t fnv(const std::vector<uint8_t>& str_vector, uint32_t hash = Seed)
{
    assert(str_vector.size());
    uint64_t h = hash;
    for (auto b : str_vector) {
        h *= Prime;
        h ^= b;
    }
    return uint32_t(h);
}


inline uint32_t fnv1a(const std::vector<uint8_t>& str_vector, uint32_t hash = Seed) 
{
    assert(str_vector.size());
    uint64_t h = hash;
    for (auto b : str_vector) {
        h ^= b;
        h *= Prime;
    }
    return uint32_t(h);
}


#endif
