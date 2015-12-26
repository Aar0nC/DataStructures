#include <stdlib.h>
#include <stdio.h>
//a stack implemented with linked lists; more space efficient, less time efficient
//Using a head pointer, push can be optimized to O(1).

typedef struct stack{
    int value;
    struct stack *top;
    struct stack *next;
}stack;

int stackTop(stack *s){
    return s->top->value;
}
stack *stackPush(stack *s, int n){
    if(s == NULL){ //removes the stackInit() function
        stack *s = malloc(sizeof(stack));
        s->value = n;
        s->next = NULL;
        s->top = s;
        return s;
    }
    //use the top pointer now
    stack *new = malloc(sizeof(stack));
    new->value = n;
    new->next = NULL;
    s->top->next = new;
    s->top = new;
    return s;
}
stack *stackPop(stack *s){
    stack *crawler = s;
    while((crawler->next)->next){
        crawler = crawler->next;
    }
    free(crawler->next);
    crawler->next = NULL;
    s->top = crawler;
    return s;
}
void stackClear(stack *s){
    while(s){
        stack *crawler = s;
        s = s->next;
        free(crawler);
    }
}
int stackSum(stack *s){
    int sum = 0;
    while(s){
        sum += s->value;
        s = s->next;
    }
    return sum;
}
void listPrint(stack *head){ //O(n)
    if(head == NULL) return;
    printf("Printing list: ");
    while(head != NULL){
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
int main(){
    stack *stackZero = NULL;
    int flag = 1;
    while(flag){
        int number;
        scanf("%d",&number);
        if(number > 0)
            stackZero = stackPush(stackZero, number);
        if(number == 0){
            stackZero = stackPop(stackZero);
        }
        else if(number < 0)
            flag = 0;
    }
    listPrint(stackZero);
    printf("sum is %d\n",stackSum(stackZero));
    printf("top is %d\n",stackTop(stackZero));
    stackClear(stackZero);
    return 0;
}