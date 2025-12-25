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

void Preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%d ",root->data);
    Preorder(root->left);
    Preorder(root->right);
}
struct Node *root = NULL;
int main() {
    root = Create();
    printf("By Traversing the Binary Tree(data items are)\n");
    Preorder(root);
 return 0;
}