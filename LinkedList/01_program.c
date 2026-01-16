#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node {
    int data;
    struct Node *previous;
    struct Node *next;
};
struct Node *head, *newnode, *temp;
void Create(){
    head = NULL;
    int choice =1;
    while(choice){
        newnode = (struct Node *) malloc(sizeof(struct Node));
        printf("Enter the data : ");
        scanf("%d",&newnode->data);
        newnode->previous = NULL;
        newnode->next = NULL;
        if(head == NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            newnode->previous = temp;
            temp = newnode;
        }
        printf("wanna continue (0 or 1): ");
        scanf("%d",&choice);
    }
}

void Display(){
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}

int main() {
    int select;
    while(select){
        int option;
        printf("Enter the choice(1 or 2) : ");
        scanf("%d",&option);
        if(option ==1){
            Create();
        }
        else if(option ==2){
            Display();
        }
        else{
            printf("invalid!\n");
        }
        printf("Wanna select again: ");
        scanf("%d",&select);
    }
 return 0;
}