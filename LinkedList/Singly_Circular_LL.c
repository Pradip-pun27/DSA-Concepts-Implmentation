#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Node {
int data;
struct Node *next;

};

struct Node *head, *newnode, *temp;

int main() {
    head = NULL;
    int choice =1;
    while(choice){
        newnode = (struct Node *) malloc(sizeof(struct Node));
        printf("Enter the data: ");
        scanf("%d",&newnode->data);
        newnode->next =NULL;
        if(head == NULL){
            temp = head = newnode;
            head->next = head;
        }
        else{
            temp->next = newnode;
            temp = newnode;
            temp->next = head;
        }
        printf("Wanna continue: ");
        scanf("%d",&choice);

    }
    printf("Elements are \n");
    temp = head;
    do{
        printf("%d ",temp->data);
        temp= temp->next;
    }while(temp!=head);
 return 0;
}