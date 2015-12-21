#include <stdio.h>
#include <stdlib.h>

//Implementation 1: Using an array
const int CAPACITY = 100;

/***********************
Time Complexity Summary:
Enqueuing and Dequeing are O(1) operations due to randome access of the array
Size of the elements array is fixed, thus inefficient use of space.
***********************/

typedef struct{
    int head; //index of element at the head
    int length;
    int elements[CAPACITY];
}queue;

queue *queueInit(int value){
    queue *new = malloc(sizeof(queue));
    for(int i = 0; i < CAPACITY; i++)
        new->elements[i] = 0;
    new->head = 0;
    new->length = 1;
    new->elements[new->head] = value;
    return new;
}
//Dequeuing
void deque(queue *new){
    if(new->length <= 0)
        return;
    new->elements[new->head] = 0;
    new->head = (new->head + 1)%CAPACITY;
    new->length--;
    return;
}
//Enqueuing
void enque(queue *new, int n){
    if(new->length > CAPACITY)
        return;
    new->elements[(new->head+new->length)%CAPACITY] = n;
    new->length++;
    return;
}
//Returning Size
int queueSize(queue *new){
    return new->length;
}
//Empty queue
int queueEmpty(queue *new){
    if(new->length == 0)
        return 1;
    else
        return 0;
}
//Contains Element
int queueContains(queue *new, int n){
    for(int i = new->head; i < new->head + new->length; i++){ //linear search
        if(new->elements[i] == n)
            return 1;
    }
    return 0; //not found
}
//Free the memory
void queueClear(queue *new){
    free(new);
    return;
}
void queuePrint(queue *new){
    for(int i = new->head; i < new->head + new->length; i++)
        printf("%d ", new->elements[i]);
    printf("\n");
}
int main(){
    queue *new = queueInit(5);
    enque(new,10);
    enque(new,15);
    enque(new,20);
    enque(new,25);
    queuePrint(new);
    deque(new);
    deque(new);
    deque(new);
    enque(new,1000);
    printf("size is %d\n", queueSize(new));
    queuePrint(new);
    printf("contains: %d\n",queueContains(new,25));
    printf("contains: %d\n",queueContains(new,2));
    queueClear(new);
    return 0;
}