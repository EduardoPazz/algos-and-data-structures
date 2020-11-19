#include "../common-header.h"

#define WORDS_QUANT 26

typedef struct aux_trie {
    struct aux_trie* alphabet[WORDS_QUANT];
    bool end_of_word;
} Trie_of_words;