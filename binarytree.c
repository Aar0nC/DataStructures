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
    int *a = (int *)_a;
    int *b = (int *)_b;
    return *a - *b;
}

typedef struct node{
    int value;
    struct node *left;
    struct node *right;
}node;

/*node *insert(node *root, int data){
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
}*/

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
    printf("%d\n", root->value);
    binaryPrint(root->left);
    binaryPrint(root->right);
}
void binaryFree(node *root){
    //again, use recursion
    /*if(root == NULL)
        return;
    node *crawler = root;
    node *rootL = root->left;
    node *rootR = root->right;
    free(crawler);
    binaryFree(rootL);
    binaryFree(rootR);*/
    if(root == NULL)
        return;
    binaryFree(root->left);
    binaryFree(root->right);
    free(root);
}
int main(){
    int array[] = {9,4,2,6,12,15,17};
    int n = sizeof(array)/sizeof(array[0]);
    qsort(array,n,sizeof(int), compare);
    node *root = buildBinaryTree(array,n);
    binaryPrint(root);
    binaryFree(root);
    return 0;
}