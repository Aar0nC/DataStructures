#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}node;

node *linkReverse(node *head){
    //deal with the first node
    /**node *prev = head;
    node *crawler = head->next;
    node *after = head->next;
    head->next = NULL;
    while(crawler->next != NULL){
        crawler->next = prev;
        prev = crawler;
        after = after->next;
        crawler = after;
    }
    return crawler;*/
    node* new_root = 0;
    while (head) {
        node* next = head->next;
        head->next = new_root;
        new_root = head;
        head = next; 
    }
    return new_root;
}

node *listInit(int value){
    node *head = malloc(sizeof(node));
    head->value = value;
    head->next = NULL;
    return head;
}
void appendNodeEnd(node *head, int value){
    if(!head) return;
    node *crawler = head;
    while(crawler->next)
        crawler = crawler->next;
    node *new = malloc(sizeof(node));
    new->value = value;
    new->next = NULL;
    crawler->next = new;
}
void listPrint(node *head){
    if(head == NULL) return;
    printf("Printing list: ");
    while(head != NULL){
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
node *nodeClear(node *head){
    while(head != NULL){
        node *crawler = head;
        head = head->next;
        free(crawler);
    }
    return head;
}
int main(){
    node *head = listInit(10);
    appendNodeEnd(head, 20);
    appendNodeEnd(head, 30);
    appendNodeEnd(head, 40);
    listPrint(head);
    head = linkReverse(head);
    listPrint(head);
    nodeClear(head);
    return 0;
}