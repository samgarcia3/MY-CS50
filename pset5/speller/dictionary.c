// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>
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
const int N = (LENGTH + 1) * 'z';

// Hash table
int total_words = 0;
node *table[N];


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Hash word to obtain a hash value
    int index = hash(word);
   
    // Access linked list at that index in the hash table
    node *cursor = table[index];
    //Traverse linked list, looking for the word(strcasecmp)
    while(cursor != NULL)
    {
        if(strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}




// Hashes word to a number
unsigned int hash(const char *word)
{
    //TODO
    unsigned long int value = 0;
    unsigned int i = 0;
    unsigned int word_len = strlen(word);
    
    // DO several rounds of multiplication
    for (; i < strlen(word); i++)
    {
        value = value * 37 + tolower(word[i]);
    }
    
    // Make sure value is 0 <= value < N
    value = value % N;
    
    return value;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
	
    // Open dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
   

    // Read strings from file one at a time
    char word[LENGTH + 1];
    while(fscanf(file, "%s", word) != EOF)
    {
    	// Create a new node
    	node *new_node = malloc(sizeof(node));
    	if (new_node == NULL)
    	{
    		return false;
    	}    	
    	
    	// Copy each word into node
    	strcpy(new_node->word, word);
    	
    	// Set next pointer to NULL
    	new_node->next = NULL;

        // Hash word to obtain a hash value
        int index = hash(word);
        if(table[index] == NULL)
        {
            table[index] = new_node;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
        
        total_words++;
    }
    
    fclose(file);
    return true;
}




// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return total_words;
}




// Unloads dictionary from memory, returning true if successful else false
bool unload(void) 
{
    // Free the linked list
    for (int i = 0; i < N; i++)
    {
        node *head = table[i];
        node *cursor = head;
        node *tmp = head;
        
        while(cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
