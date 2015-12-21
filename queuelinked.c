#include <stdio.h>
#include <stdlib.h>

/*************************************
Implementation 2: Using a linked list
Time Complexity Summary:
Enqueing is a O(n) operation (appending at the beginning)
Dequeing is a O(1) operation (appending at the end)
Efficient use of space when compared to the array implemenation.
**************************************/

typedef struct queue{
    int value;
    struct queue *next;
}queue;

queue *queueInit(int value){
    queue *root = malloc(sizeof(queue));
    root->value = value;
    root->next = NULL;
    return root;
}
//Dequeuing
queue *deque(queue *head){
    //delete the first node
    queue *crawler = head;
    head = head->next;
    free(crawler);
    return head;
}
//Enqueuing
void enque(queue *head, int n){
    while(head->next)
        head = head->next;
    queue *new = malloc(sizeof(queue));
    head->next = new;
    new->next = NULL;
    new->value = n;
}

//Returning Size
int queueSize(queue *head){
    int size = 0;
    while(head){
        head = head->next;
        size++;
    }
    return size;
}

//Empty queue
int queueEmpty(queue *head){
    if(queueSize(head) == 0)
        return 1;
    else
        return 0; 
}
//Contains Element
int queueContains(queue *head, int n){
    //linear search through the queue
    for(;head;head = head->next){
        if(head->value == n)
            return 1;
    }
    return 0;
}

//Free the memory
void queueClear(queue *head){
    while(head){
        queue *crawler = head;
        head = head->next;
        free(crawler);
    }
}
//Print the queue
void queuePrint(queue *head){
    while(head){
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main(){
    queue *head = queueInit(5);
    enque(head,10);
    enque(head,15);
    enque(head,20);
    enque(head,25);
    queuePrint(head);
    head = deque(head);
    head = deque(head);
    head = deque(head);
    enque(head,1000);
    printf("size is %d\n", queueSize(head));
    queuePrint(head);
    printf("contains: %d\n",queueContains(head,25));
    printf("contains: %d\n",queueContains(head,2));
    queueClear(head);
    return 0;
}