#include "Trie.h"
#include <cstring>
#include <vector>

Trie::Trie() : parent(nullptr), count(0), word(nullptr), found(false) {
    for (int i = 0; i < ALPHABET_LEN; i++) children[i] = nullptr; 
}

Trie::~Trie() {
    for (int i = 0; i < ALPHABET_LEN; i++) delete children[i];
}

void Trie::insert(char w[]) 
{
    Trie* node = this;
    for (size_t i = 0; w[i]; i++) {
        int letter_idx = word[i] - 'a'; // char to int 
        if ( (w[i] == 'q') && (w[i+1] == 'u')) { // concat 'qu' into one 
            i++;
        }
        ++node->count; 

        if (!node->children[letter_idx]) { 
            node->children[letter_idx] = new Trie();
            node->children[letter_idx]->parent = node;
        }
        node = node->children[letter_idx];
    }
    node->word = w;
}

Trie* Trie::lookup(int letter_idx) 
{
    Trie* next = children[letter_idx];
    if (next && next->word && !next->found) {
        next->found = True;
        if (next->parent) next->parent->count--;
    }
    return next;
}

template<typename OutIt>
void Trie::getFoundWords(OutIt out) 
{
    if (found && word) *out++ = word; // add word to our iterator
    for (int i = 0; i < ALPHA_SIZE; i++) { 
        if (children[i]) children[i] -> getFoundWords(out); 
    }
}
