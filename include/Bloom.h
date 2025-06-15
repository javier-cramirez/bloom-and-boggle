#ifndef BLOOM_H
#define BLOOM_H

#include <vector>
#include <cstdint>
#include <cstddef>
#include <cassert>
#include <cmath>

#define LN2_SQUARED 0.4804530139182014246671025263266649717305529515945455
#define LN2 0.6931471805599453094172321214581765680755001343602552


class BloomFilter {
public:
    BloomFilter(size_t num_elements, double fp_rate, uint32_t seed = 0);

    void insert(const std::vector<uint8_t>& key);

    bool contains(const std::vector<uint8_t>& key) const;

    void clear();

    void reset(uint32_t new_seed);

private:
    uint32_t hash(uint32_t idx, const std::vector<uint8_t>& str_vector) const;

    size_t num_bits;
    size_t num_bytes;
    unsigned int num_hash_fns;
    uint32_t seed_;
    std::vector<uint8_t> bit_array;
    bool is_full_;
    bool is_empty_;
};

#endif
