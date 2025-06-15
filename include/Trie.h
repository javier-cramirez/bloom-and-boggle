#pragma once
#include <string>
#include <array>

const int ALPHABET_LEN = 26;

class Trie {
public:
    Trie* children[ALPHABET_LEN];
    Trie* parent;
    int count; // how many suffixes our node has
    char* word; // store a completed word
    bool found; // check if a word was found
    Trie();
    ~Trie();
    
    void insert(char w[]);

    inline Trie* lookup(int letter_idx); // marks found if this index completes a word, else NULL

    template<class OutIt>
    void getFoundWords(OutIt out); // pushes all found words into a vector
};
