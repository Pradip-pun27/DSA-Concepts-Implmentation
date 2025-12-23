#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node {
int data;
struct Node *previous;
struct Node *next;
};
struct Node *head, *temp, *newnode,*prev;
int main(){
    head = NULL;
    int choice =1;
    while(choice){
        newnode = (struct Node *) malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next =NULL;
        newnode->previous = NULL;
        prev = NULL;
        if(head == NULL){
            temp = head = newnode;
        }
        else{
            temp->next = newnode;
            temp->next->previous = temp;
            temp = newnode;
            
        }
        printf("Wanna continue: ");
        scanf("%d",&choice);

    }
    printf("%d %d",temp->previous->data,temp->data);
return 0;
}