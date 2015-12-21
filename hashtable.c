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
/*
Hash Tables have a key and a value; we have an associative array
Key: Paul
Value: phone # 
The hash functions gets a key as inputs, and returns a value (index in an array). 
The hash function should return the same value if the index is the same 
Using seperate chaining is the preferable method to deal with conflicts
O(n/k) where k is the size of the array (k times faster than a single linked list assuming an even distribution)
*/
Potential Hashing Functions:
DJB2;
unsigned int hashFunction(hash_table *hashtable, char *str){
    unsigned long hash = 5381;
    for(; *str; str++)
        hash += hash << 5 + *str;
    return hash%(hashtable->size);
}
Lose Lose
unsigned int hashFunction(hash_table *hashtable, char *str){
    unsigned int hash = 0;
    for(; *str; str++)
        hash+= *str;
    return hash%(hashtable->size);
}