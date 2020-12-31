// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1000; // change the number if necessary

// Hash table
node *table[N];

// Dict word count global variable
unsigned int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    int len = strlen(word);
    char tmp[len + 1];
    for (int i = 0; i < len; i++)
    {
        tmp[i] = tolower(word[i]);
    }
    tmp[len] = '\0'; //tmp is a lowercase copy of word now

    unsigned int index = hash(tmp);

    // bucket doesn't exist
    if (table[index] == NULL)
    {
        // gtfo
        unload();
        return 1;
    }
    else
    {
        node *cursor = table[index];
        // loop until list ends
        while (cursor != NULL)
        {
            // case sensitive comparison
            if (strcasecmp(cursor->word, tmp) == 0)
            {
                return true;
            }
            else
            {
                // no match found. continue
                cursor = cursor->next;
            }
        }
    }
    return false;
}

// Hashes word to a number
// TODO

/* credits to...
https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/
*/

// I have no clue!
// it seems to break on apostropy. plus mem issue. otherwise very fast
// unsigned int hash(const char *word)
// {
//     unsigned int hash = 0;
//     for (int i = 0; word[i] != '\0'; i++)
//     {
//         hash = (hash << 2) ^ word[i];
//     }
//     return hash % N;
// }

// another one!
// i have no clue either!!
unsigned int hash(const char *word)
{
    unsigned int hash = 10000; // random number!
    int c = *word;
    while (c == *word++)
    {
        hash = ((hash << 2) + hash) + c;
    }
    return hash % N;
}

// this one is not optimized but works
// unsigned int hash(const char *word)
// {
//     unsigned int tmp, hash_val = 0;
//     // for each alphabet in a word
//     for (int n = 0; word[n] < '\0'; n++)
//     {
//         // for a - z
//         if (isalpha(word[n]))
//         {
//             // setting a to 0 won't work
//             tmp = tolower(word[n]) - 'a' + 1;
//         }
//         // for <'>
//         else
//         {
//             // tmp = 27; //this would work
//             tmp = 0; //this might work too
//         }
//         hash_val = ((hash_val << 2) + tmp) % N;
//     }
//     return hash_val;
// }

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    // Open file
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return 1;
    }
    char buffer[LENGTH+1];

    // loop all words until file ends
    while (fscanf(file, "%s", buffer) != EOF)
    {
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            // gtfo
            // unload();
            return 1;
        }

        // copy buffer into temp node
        strcpy(tmp->word, buffer);
        tmp->next = NULL;

        unsigned int index = hash(tmp->word);

        // bucket is blank
        if (table[index] == NULL)
        {
            table[index] = tmp;
        }
        // something exists
        else
        {
            tmp->next = table[index];
            table[index] = tmp;
        }

        // found a word
        word_count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if (!word_count) // another way of saying dict is not loaded
    {
        return 0;
    }
    else
    {
        return word_count;
    }
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    // loop through all the buckets
    for (int n = 0; n < N; n++)
    {
        node *cursor = table[n];
        // free mem for each bucket
        while (cursor != NULL)
        {
            node *tmp = cursor;
            // goto next linked list
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
