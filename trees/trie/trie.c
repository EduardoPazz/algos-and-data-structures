#include "./trie.h"

int char_index(char c)
{
    /* 
        Here, we are moving the index of the 26 letters 
        of the alphabet between 0-25. 
        The unicode index of letter 'a' is 97

        Example: 
            - letter 'a'
            97 - 97 == 0 (first letter)

            - letter 'c'
            99 - 97 == 2 (third letter)
     */

    return (char) c - 97;
}

Trie_of_words* create_trie_node() {
    Trie_of_words* trie = (Trie_of_words*) malloc(sizeof(Trie_of_words));

    trie->end_of_word = false;

    for (int i = 0; i < WORDS_QUANT; i++)
    {
        trie->alphabet[i] = NULL;
    }
    
}

Trie_of_words* initialize_trie()
{
    return(create_trie_node());
}

void insert_word(Trie_of_words* trie, char* word) {
    Trie_of_words* jumper = trie;

    for (
        int length = strlen(word), level = 0, index; 
        level < length;
        level++
    ) 
    {
        index = char_index(word[level]);
        if (jumper->alphabet[index] == NULL) jumper->alphabet[index] = create_trie_node();
        jumper = jumper->alphabet[index];
    }
    jumper->end_of_word = true;
}

int main()
{
    /* code */
    return 0;
}
