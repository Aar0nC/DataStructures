#include <stdio.h>
#include <stdlib.h>

/***********
Binary search tree: a tree where all nodes to the left precede the root 
in some ordered set, and the nodes to the right proceed the root in the same ordered set. 
Each branch is of degree two. 
The longest path from the root to a leaf is the depth of the tree
Binary Search trees naturally lend themselves to recursive methods
 
Operations to code: 
1. Insertion / Creation
2. Deletion
3. Printing
4. Searching
5. Traversing
6. Freeing 
************/

int compare(const void *_a, const void *_b){
    return *(int *a)-*(int *b);
}

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}node;

node *insert(node *root, int data){
    if(root = NULL){
        root = malloc(sizeof(node));
        root->value = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if(data < r->value)
        root->left = buildBinary(r->left, data);
    else
        root->right = insert(r>right,data);
    return root
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
    int n = sizeof(a)/sizeof(a[0]);
    qsort(array,n,sizeof(int), compare);
    node *root = NULL;
    root = insert(root);
    binaryPrint(root);
    return 0;
}