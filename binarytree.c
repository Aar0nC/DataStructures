#include <stdio.h>
#include <stdlib.h>

/**
Binary search tree: a tree where all nodes to the left precede the root 
in some ordered set, and the nodes to the right proceed the root in the same ordered set. 
Each branch is of degree two. 
The longest path from the root to a leaf is the depth of the tree
Binary Search trees naturally lend themselves to recursive methods
**/

int compare(const void *_a, const void *_b){
    return *(int *a)-*(int *b);
}

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}node;

node *buildBinary(int *array, int size){
    if(size <= 1){
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    int middle = n/2;
    node *root = malloc(sizeof(node))
    root->value = array[middle];
    root->left = buildBinary(array, middle);
    root->right = buildBinary(array+middle, n-middle);
}
void binaryPrint(node *root){
    if(root == NULL) return;
    node *crawler = root;
    printf("%d", root->value);
    return binaryPrint(root = root->left);
    return binaryPrint(root = root->right);
} 
int main(){
    int array[10] = {1,2,5,7,10,11,12,14,16,20};
    qsort(array,sizeof(array)/sizeof(array[0]),sizeof(int), compare);
    node *root = buildBinary(array, sizeof(a)/sizeof(a[0]));
    binaryPrint(root);
    return 0;
}