#include <stdio.h>


typedef struct list{
    char *word;
    struct list *next;
}list;

typedef struct hash_table{
    int size;
    list **table;
}hash_table;

hash_table *hashInit(int size){
    hash_table *hash_new = malloc(sizeof(hash_table));
    if(!hash_new) return 0;
    hash_new->size = size;
    hash_new->table = calloc(hash_table->size, sizeof(list *));
    return hash_new;
}
unsigned int hashFunction(hash_table *hashtable, char *str){
    unsigned int hash = 5381;
    int c;
    for(; *str != '\0'; str++)
        hash += hash<<5 + *str;
    return hash%(hashtable->size);
}
list *hashLookup(hash_table *hashtable, char *string){
    unsigned int index = hashFunction(hashtable, string);
    list *ptr = hashtable->table[index];
    for(; ptr; ptr = ptr->next){
        if(strcmp(string, ptr->word) == 0)
            return ptr;
    }
    return NULL;
}
void addString(hash_table *hashtable, char *str){
    unsigned int index = hashFunction(hashtable, str);
    list *new = malloc(sizeof(list));
    new->word = str;
    new->next = hashtable->table[i];
    hashtable->table[i] = new;
    
    return 0;
}
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