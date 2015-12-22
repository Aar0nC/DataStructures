#include <stdio.h>
#include <stdlib.h>
/*Remaining:
2. Deletion
4. Searching
5. Traversing
*/

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
int main(){
    int array[] = {1,2,5,7,10,11,12,14,16,20};
    int n = sizeof(array)/sizeof(array[0]);
    qsort(array,n,sizeof(int), compare);
    node *root = buildBinaryTree(array,n);
    binaryPrint(root);
    printf("\n");
    binaryFree(root);
    return 0;
}