#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    hash_new->table = calloc(hash_new->size, sizeof(list *));
    return hash_new;
}
unsigned int hashFunction(hash_table *hashtable, char *str){
    char c = str[0];
    if(c >= 'A' && c <= 'Z')
        return c-'A';
    else
        return c-'a';
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
    new->next = hashtable->table[index];
    hashtable->table[index] = new;
    return;
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
    free(hashtable->table);
    free(hashtable);
    return;
}
void hashPrint(hash_table *hashtable){
    for(int i = 0; i < hashtable->size; i++){
        if(hashtable->table[i] == 0) printf("empty\n");
        else{
            while(hashtable->table[i]){
                printf("%s ", hashtable->table[i]->word);
                hashtable->table[i] = hashtable->table[i]->next;
            }
            printf("\n");
        }
    }
}
int main(){
    hash_table *new = hashInit(26);
    addString(new, "aaron");
    addString(new, "cotter");
    addString(new, "jim");
    addString(new, "joe");
    addString(new, "john");
    addString(new, "tommy");
    printf("%s\n",hashLookup(new, "tommy")!= NULL ? "found" : "not found");
    printf("%s\n",hashLookup(new, "not in here")!= NULL ? "found" : "not found");
    hashPrint(new);
    hashFree(new);
}