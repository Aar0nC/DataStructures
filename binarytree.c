#include <stdio.h>
#include <stdlib.h>

int compare(const void *_a, const void *_b){
    int *a = (int *)_a;
    int *b = (int *)_b;
    return *a - *b;
}

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}node;

node *buildBinaryTree(int *array, int n){
    if(n == 0)
        return NULL;
    int middle = n/2;
    node *new = malloc(sizeof(node));
    new->value = array[middle];
    new->left = buildBinaryTree(array, middle);
    new->right = buildBinaryTree(array+middle+1, n-middle-1);
    return new;
}
node *nodeInsert(node *root, int value){
    if(root == NULL){
        root = malloc(sizeof(node));
        root->left = NULL;
        root->right = NULL;
        root->value = value;
    }
    else if(value > root->value)
        root->right = nodeInsert(root->right, value);
    else
        root->left = nodeInsert(root->left, value);
    return root;
}
void binaryPrint(node *root){
    if(root == NULL)
        return;
    printf("%d ", root->value);
    binaryPrint(root->left);
    binaryPrint(root->right);
}
void binaryFree(node *root){
    if(root == NULL)
        return;
    binaryFree(root->left);
    binaryFree(root->right);
    free(root);
}
node *binarySearch(node *root, int value, node **parent){
    if(root == NULL)
        return NULL;
    if(root->value == value)
        return root;
    *parent = root;
    if(value > root->value)
        return binarySearch(root->right, value,parent);
    else
        return binarySearch(root->left, value,parent);
}

int main(){
    int array[] = {1,2,5,7,10,11,12,14,16,20};
    int n = sizeof(array)/sizeof(array[0]);
    qsort(array,n,sizeof(int), compare);
    node *root = buildBinaryTree(array,n);
    node *parent = NULL;
    binaryPrint(root);
    printf("\n");
    printf("%sfound\n", binarySearch(root,16, &parent) != NULL ? "": "not ");
    binaryFree(root);
    
    node *parent2 = NULL;
    node *second = NULL;
    second = nodeInsert(second, 33);
    second = nodeInsert(second, 45);
    second = nodeInsert(second, 23);
    second = nodeInsert(second, 99);
    binaryPrint(second);
    printf("\n");
    printf("%sfound\n", binarySearch(second, 23, &parent2) != NULL ? "": "not ");
    binaryFree(second);
    return 0;
}