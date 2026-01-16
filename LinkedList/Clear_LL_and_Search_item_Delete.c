#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head, *newnode, *temp;

void Display(){
int count_nodes=0;
    if(head == NULL){
    printf("List is Empty\n");
    return;
}
    for(temp= head; temp!=NULL; temp = temp->next){
        count_nodes++;
        printf(" Node-%d: %d\n",count_nodes,temp->data);  
}
    printf("%d nodes was created\n",count_nodes);
}

void Clear(){
    if(head ==NULL){
        printf("List is Empty!\n");
        return;
    }
    newnode = head;
    struct Node *prev = NULL;
    while(newnode!=NULL){
        prev = newnode->next;
        free(newnode);
        newnode = prev;
    }
    printf("ALL done\n");
    head = NULL;
}

void Find_Delete(){
    if(head == NULL){
        printf("Empty L.L\n");
        return;
    }
    temp = head;
    int item,flag =0;
    printf("Enter the data : ");
    scanf("%d",&item);
    struct Node *prev = NULL;
    while(temp!=NULL){
        if(temp->data == item){
            flag =1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(flag){
        if(prev == NULL){
            head= head->next;
            free(temp);
            printf("Operation is done\n");
        }
        else{
            prev->next = temp->next;
            free(temp);
            printf("Operation is done\n");
        }
    }
    else{
        printf("Not found!\n");
    }
}

int main(){
    head =NULL;
    int continues=1;
    while(continues){
        newnode = (struct Node *) malloc(sizeof(struct Node));
        printf("Enter data : ");
        scanf("%d",&newnode->data);
        newnode->next = NULL;
        if(head == NULL){
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            temp = newnode;
        }
        printf("Wanna Resume this insertion operation ( 0 0r 1 ): ");
        scanf("%d",&continues);
    }
    int choice=1,select;
    while(choice){
        printf("1.Display the data items in the nodes of a linked list\n");
        printf("2.Search and Delete\n");
        printf("3.Clear\n");
        printf("\n\nEnter the choice (1,2,3):");
        scanf("%d",&select);
        if(select ==1){
            Display();
        }
        else if(select ==2){
            Find_Delete();
        }
        else if(select ==3){
           Clear();
        }
        else{
            printf("\nInvalid option given!\n");
        }
        printf("\nWanna continue above 3 operations(0 0r 1):");
        scanf("%d",&choice);
    }
    return 0;
}