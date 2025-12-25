#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *Create(){
    int n;
    struct Node *newnode;
    newnode = (struct Node *) malloc(sizeof(struct Node));
    printf("\nEnter the data item ( -1 for no node ) : ");
    scanf("%d",&n);
    if(n ==-1){
        return NULL;
    }
    newnode->data = n;
    printf("\nEnter left child of %d",n);
    newnode->left = Create();
    printf("\nEnter right child of %d",n);
    newnode->right = Create();
    return newnode;
}

struct node *root = NULL;
int main() {
    root = Create();
 return 0;
}