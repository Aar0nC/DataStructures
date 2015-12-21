#include <stdio.h>

//c implementation of a hash
typedef struct list{
    char *word;
    struct list *next;
}list;

//need to define the hash table struct
typedef struct hash_table{
    int size; //size of the hash;
    list **table; //an array of pointers
}hash_table;

//Function 1: Initializing the hash table.
hash_table *hashInit(int size){
    hash_table *hash_new = malloc(sizeof(hash_table));
    if(!hash_new) return 0;
    hash_new->size = size;
    hash_new->table = calloc(hash_table->size, sizeof(list *));
    return hash_new;
}
//Function 2: Our relatively simple hash function
//should return an index; this will an unsigned integer
unsigned int hashFunction(hash_table *hashtable, char *str){
    unsigned int hashvalue = 0;
    //now need to make a calculation to determine the hash value
    //going to invoke the widely used DJB2 hashing function
    unsigned long hash = 5381;
    int c;
    for(; *str != '\0'; str++)
        hash += hash<<5 + *str;
    return hash%(hashtable->size); //an index
}
//Function 3: String Lookup
//This is easy, we take a string, computes its hash value, and perform a linear search
//on the linked lists
list *hashLookup(hash_table *hashtable, char *string){
    unsigned int index = hashFunction(hashtable, string);
    list *ptr = hashtable->table[index];
    for(; ptr; ptr = ptr->next){
        if(strcmp(string, ptr->word) == 0)
            return ptr;
    }
    return NULL;
}
//Function 4: Inserting a string.
//Compute the hash value, go to the index, and append to the linked list as appropriate
void addString(hash_table *hashtable, char *str){
    unsigned int index = hashFunction(hashtable, str);
    
    /**this appends to end, better to append to beginning; we dont care about ordering
    list *crawler = hashtable->table[index];
    while(crawler->next)
        crawler = crawler->next;
    list *new = malloc(sizeof(list));
    new->word = str;
    new->next = NULL;
    crawler->next = new;*/
    list *new = malloc(sizeof(list));
    new->word = str;
    new->next = hashtable->table[i];
    hashtable->table[i] = new;
    
    return 0;
}
//Function 5: Freeing the hashtable;
void hashFree(hash_table *hashtable){
    for(int i = 0; i < hashtable->size; i++){
        list *crawler = hashtable->table[i];
        while(crawler){
            list *temp = crawler;
            crawler = crawler->next;
            free(temp);
        }
    }
    free(hashtable->table)
    free(hashtable);
}