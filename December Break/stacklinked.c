#include <stdlib.h>
#include <stdio.h>
//a stack implemented with linked lists; more space efficient, less time efficient
//O(n) access, instead of O(1) access.
typedef struct stack{
    int value;
    struct stack *next;
}stack;

stack *stackInit(){
    stack *s = malloc(sizeof(stack));
    s->value = 0;
    s->next = NULL;
    return s;
}
int stackTop(stack *s){
    while(s->next)
        s = s->next;
    return s->value;
}
void stackPush(stack *s, int n){
    if(!s) return;
    while(s->next)
        s = s->next;
    stack *new = malloc(sizeof(stack));
    new->value = n;
    new->next = NULL;
    s->next = new;
}
void stackPop(stack *s){
    stack *crawler = s;
    while((crawler->next)->next){
        crawler = crawler->next;
    }
    free(crawler->next);
    crawler->next = NULL;
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
void listPrint(stack *head){
    if(head == NULL) return;
    printf("Printing list: ");
    head = head->next;
    while(head != NULL){
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}
int main(){
    stack *stackZero = stackInit();
    int flag = 1;
    while(flag){
        int number;
        scanf("%d",&number);
        if(number > 0)
            stackPush(stackZero, number);
        if(number == 0){
            stackPop(stackZero);
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