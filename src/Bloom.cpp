#include "Bloom.h"
#include "hash.h"
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
    m_bits = size_t(std::ceil(m));
    m_bytes = (m_bits + 7) / 8;
    bits_.assign(m_bytes, 0);

    k = (m / n) * LN2;

    k_hashes = unsigned(std::round(k));
}

uint64_t BloomFilter::hash(unsigned idx, const vector<uint8_t>& data_to_hash) const 
{
    
}

void BloomFilter::insert(const vector<uint8_t>& key) 
{
    if (is_full_) return;

    for (unsigned i = 0; i < n_hash_fns; i++) {
        uint64_t h = Hash(i, key);
        size_t bit = h % m_bits;
        // bits_[h >> 3] |= (1 << (h & 7))
        bits_[bit >> 3] |= (1 << (bit & 7));
    }
    is_empty_ = false;
}

bool BloomFilter::contains(const vector<uint8_t>& key) const
{
    if (is_full_) return true;
    if (is_empty_) return false;

    for (unsigned i = 0; i < n_hash_fns; i++) {
        uint64_t h = Hash(i, key);
        size_t bit = h % m_bits;
        if ((bits_[bit >> 3] |= (1 << (bit & 7))) == 0) {
            return false; // check if the bit is occupied
        }
    }
    return true;
}

void BloomFilter::clear() 
{
    std::fill(bits_.begin(), bits_.end(), 0);
    is_full_ = false;
    is_empty_ = true;
}

void BloomFilter::reset(uint32_t new_seed) 
{
    seed_ = new_seed;
    clear();
}
