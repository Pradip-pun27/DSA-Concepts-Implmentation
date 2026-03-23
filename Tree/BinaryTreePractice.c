#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node {
int data;
struct Node *left,*right;
};

struct Node *Create(){
    int x;
    struct Node *newnode;
    newnode = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter the data (-1 for no node):");
    scanf("%d",&x);
    if(x==-1){
        return NULL;
    }
    newnode->data = x;
    printf("Enter the left child of %d\n",x);
    newnode->left = Create();
    printf("Enter the right child of %d\n",x);
    newnode->right = Create();

    return newnode;
}
int main() {
    struct Node *root;
    root=Create();
 return 0;
}