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

void Inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    Preorder(root->left);
    printf("%d ",root->data);
    Preorder(root->right);
}

void Postorder(struct Node *root){
    if(root == NULL){
        return;
    }
    Preorder(root->left);
    Preorder(root->right);
    printf("%d ",root->data);
}

struct Node *root = NULL;
int main() {
    root = Create();
    printf("\nThe Preorder traversal of a B.T is\n");
    Preorder(root);
    printf("\nThe Inororder traversal of a B.T is\n");
    Inorder(root);
    printf("\nThe Postorder traversal of a B.T is\n");
    Postorder(root);
 return 0;
}