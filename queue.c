#include <stdio.h>
#include <stdlib.h>

//Implementation 1: Using an array
const int CAPACITY = 100;

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
    if(new->length <= 0) return;
    new->head--;  //= (new->head+1)%CAPACITY;
    new->length--;
    return;
}
//Enqueuing
void enque(queue *new, int n){
    //shift everything down one position and insert
    if(new->length+1 > CAPACITY) return;
    if(new->length > 1){
        for(int i = new->length-2; i <= 0; i--){
            new->elements[i+1] = new->elements[i];
        }
        new->elements[0] = n;
    }
    if(new->length == 1){
        new->elements[new->length] = new->elements[0];
        new->elements[0] = n;
    }
    new->length++;
    new->head++;
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
    for(int i = 0; i < new->length; i++){ //linear search
        if(new->elements[i] == n)
            return 1;
    }
    return 0; //not found
}
void queueClear(queue *new){
    free(new->elements);
    free(new);
    return;
}
void queuePrint(queue *new){
    for(int i = 0; i < new->length; i++)
        printf("%d ", new->elements[i]);
    printf("\n");
}
int main(){
    queue *new = queueInit(5);
    enque(new,10);
    //enque(new,15);
    //enque(new,20);
    //enque(new,25);
    queuePrint(new);
    return 0;
}