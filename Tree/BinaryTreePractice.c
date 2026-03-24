#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node * Create(){
    int n;
    struct Node * newnode = (struct Node*) malloc(sizeof(struct Node));
    printf("Enter the Value (-1 for no node): ");
    scanf("%d", &n);
    if(n == -1){
        free(newnode);  // Free the allocated memory if no node is created
        return NULL;
    }
    newnode->data = n;
    printf("Enter the left child of %d ", n);
    newnode->left = Create();
    printf("Enter the right child of %d ", n);
    newnode->right = Create();
    return newnode;
}

void freeTree(struct Node *node) {
    if (node == NULL) {
        return;  // Base case: nothing to free
    }
    // Recursively free left and right subtrees first
    freeTree(node->left);
    freeTree(node->right);
    // Then free the current node
    free(node);
}

int main() {
    struct Node *root;
    root = Create();
    
    // ... (add any code here to use the tree, e.g., traversals)
    
    freeTree(root);
    root = NULL;  // Optional: set to NULL to avoid dangling pointer
    
    return 0;
}