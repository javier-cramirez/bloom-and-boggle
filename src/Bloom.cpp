#include "Bloom.h"
#include "HashFunctions.h"
#include <limits>

using std::vector;

BloomFilter::BloomFilter(
        size_t n_elements, 
        double fp_rate, // epsilon, our false positive bound
        uint32_t seed) : seed_(seed), is_full_(false), is_empty_(true) 
{    
    double n = double(n_elements);

    // the optimal number of bits is m, which is given by the wiki entry:
    // https://en.wikipedia.org/wiki/Bloom_filter
    double m = - n * std::log(fp_rate) / LN2_SQUARED;
    num_bits = size_t(std::ceil(m));
    num_bytes = (num_bits + 7) / 8;
    bit_array.assign(num_bytes, 0);

    k = (m / n) * LN2;

    num_hash_fns = unsigned(std::round(k));
}

uint64_t BloomFilter::hash(unsigned idx, const vector<uint8_t>& str_vector) const 
{
    vector<uint8_t> bytes(data_to_hash.begin(), data_to_hash.end());

    uint32_t hash_32 = fnv1a(bytes, static_cast<uint32_t>(idx));
    return uint64_t(hash_32) % num_bits;
}

void BloomFilter::insert(const vector<uint8_t>& key) 
{
    if (is_full_) return;

    for (unsigned i = 0; i < n_hash_fns; i++) {
        uint64_t h = hash(i, key);
        size_t bit = h % num_bits;
        // bit_array[h >> 3] & (1 << (h & 7))
        bit_array[bit >> 3] |= (1 << (bit & 7));
    }
    is_empty_ = false;
}

bool BloomFilter::contains(const vector<uint8_t>& key) const
{
    if (is_full_) return true;
    if (is_empty_) return false;

    for (unsigned i = 0; i < n_hash_fns; i++) {
        uint64_t h = Hash(i, key);
        size_t bit = h % num_bits;
        if ((bit_array[bit >> 3] & (1 << (bit & 7))) == 0) {
            return false; // check if the bit is occupied
        }
    }
    return true;
}

void BloomFilter::clear() 
{
    std::fill(bit_array.begin(), bit_array.end(), 0);
    is_full_ = false;
    is_empty_ = true;
}

void BloomFilter::reset(uint32_t new_seed) 
{
    seed_ = new_seed;
    clear();
}
