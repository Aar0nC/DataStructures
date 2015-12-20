#include <stdio.h>
#include <stdlib.h>

//define our linked list for seperate chaining
typedef struct list{
    char *string;
    struct list *next;
}list;
//now a hash table structure
typedef struct hash{
    int size; //size of the table
    list **table; //the table elements
}hash;

//functions that need to be implemented
/**
1. Create a table
2. Hash function
3. Free a table
4. Insertion 
5. Lookup
*/

hash *hashCreate(int size){
    hash *newTable = malloc(sizeof(has));
    if(!newTable) return NULL;
    //have allocated memory for the table structure
    newTable->table = malloc(sizeof(list)*size); //have allocated size lists
    newTable->size = size;
    for(int i = 0; i < size; i++){
        newTable->table[i] = NULL;
    }
    return newTable;
}
//an array where each element is a pointer to another linked list
list *array[size];

CS50 Implementation;
typedef struct node{
    char *word;
    struct node *next;
}node;

node *table[CAPACITY];

