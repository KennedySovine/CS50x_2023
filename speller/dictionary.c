// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5381;

unsigned int count=0;

// Hash table
node *table[N];

unsigned int bucket = 0;

// Returns true if word is in dictionary, else false
bool check(const char* word)
{
    // TODO
    bucket = hash(word);

    node* checker = table[bucket];

    while (checker != NULL){
        if(strcasecmp(checker->word, word) == 0){
            return true;
        }
        checker = checker->next;
    }
    //free(checker->word);
    //free(checker->next);
    free(checker);
    return false;
}

// Hashes word to a number
unsigned int hash(const char* word)
{
    // TODO
    int index = 0;

    for (int i = 0; word[i] != '\0'; i++){
        index += tolower(word[i]);
    }
    return index % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH +1];
    FILE* dico = fopen(dictionary, "r");
    if (dico != NULL){
            while (fscanf(dico, "%s", word) != EOF){
                node *ne = malloc(sizeof(node));

                if(ne != NULL){
                    bucket = hash(word);
                    strcpy(ne->word, word);
                    ne->next = table[bucket];
                    table[bucket] = ne;
                    count++;
                }
            }
            fclose(dico);
    }
    else{
        return false;
    }

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++){
        node *cursor = table[i];

        while(cursor){
            node* tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        if ( i == N - 1 && cursor == NULL){
            return true;
        }
    }
    return false;
}
