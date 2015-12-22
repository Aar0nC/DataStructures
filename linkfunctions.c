#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int value;
    struct node *next;
}node;

int nodeCount(node *head);

void printLast(node *head){
    if(head == NULL) return;
    node *crawler = head;
    while(crawler->next != NULL)
        crawler=crawler->next;
    printf("%d\n", crawler->value);
}
node *appendNode(node *head, int value){ //inserts a new node at the beginning of the list
    node *new = malloc(sizeof(node));
    if(new == NULL) return (node *) 0;
    new->value = value;
    new->next = head;
    head = new;
    return head;
}
void appendNodeEnd(node *head, int value){
    node *crawler = head;
    while(crawler->next)
        crawler = crawler->next;
    node *new = malloc(sizeof(node)); 
    new->value = value;
    new->next = NULL;
    crawler->next = new;
}
void insertNode(node *head, int index, int value){
    if(head == NULL) return;
    if(index < 0 || index >= nodeCount(head)) return;
    node *new = malloc(sizeof(node));
    new->next = NULL;
    new->value = value;
    
    node *crawler = head;
    for(int i = 0; i < index; i++){
        if(crawler->next != NULL)
            crawler = crawler->next;
    }
    new->next = crawler->next;
    crawler->next = new;
}
node *deleteNode(node *head, int index){
    node *crawler = head;
    if(index == 0){ //special treatment for deleting the head node
        head = crawler->next;
        free(crawler);
        return head;
    }
    else{
        for(int i = 1; i < index;i++){
            if(crawler->next != NULL)
                crawler = crawler->next;
        }
        node *temp = crawler->next;
        crawler->next = temp->next;
        free(temp);
        return head;
    }
}
int nodeCount(node *head){
    if(head == NULL) return 0;
    int count = 0;
    while(head !=NULL){
        head = head->next;
        count++;
    }
    return count;
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
    if(head == NULL)
        return 0;
    nodeClear(head->next);
    free(head);
}

int main(){
    node *head = NULL;
    head = appendNode(head,10);
    head = appendNode(head, 20);
    head = appendNode(head, 30);
    appendNodeEnd(head, 100);
    listPrint(head);
    insertNode(head, 2, 50);
    printf("Node count: %d\n", nodeCount(head));
    listPrint(head);
    printf("\n\n");
    head = deleteNode(head,1);
    printf("Node count: %d\n", nodeCount(head));
    listPrint(head);
    printLast(head);
    head = nodeClear(head);
}
