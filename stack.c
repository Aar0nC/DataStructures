#include <stdio.h>

const int STACK_MAX = 100;

typedef struct stack{
    int data[STACK_MAX];
    int top;
}Stack;

void stackInit(Stack *s){
    s->top = 0;
}
int stackTop(Stack *s){
    if(!s->top) return -1;
    return s->data[s->top];
}
void stackPush(Stack *s, int n){
    if(s->top < STACK_MAX)
        s->data[s->top++] = n;
    else
        printf("Error, stack full\n");
}
void stackPop(Stack *s){
    if(s->top == 0) printf("Error: Stack empty\n");
    else
        s->top--;
}