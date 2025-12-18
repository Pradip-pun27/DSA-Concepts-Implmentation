#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *link;
};
struct Node *head,*newnode, *temp;
int global_count = 0;

void Display(){
int count_nodes=0;
for(temp= head; temp!=NULL; temp = temp->link){
    count_nodes++;
    printf(" Node-%d: %d\n",count_nodes,temp->data);  
}
printf("%d nodes was created\n",count_nodes);
}

void Delete_First(){
    temp = head;
    head = head->link;
    free(temp);
    global_count--;
    printf("\nOperation has been successfully finished\n");
}

void Delete_Last(){
    newnode = head;
    while(newnode->link !=NULL){
        temp = newnode;
        newnode= newnode->link;
    }
    temp->link = NULL;
    free(newnode);
    global_count--;
    printf("\nOperation has been successfully finished\n");
}

void Delete_Desired(){
    int position,i;
    printf("Enter the Position of the node u Wanna remove from the linked list: ");
    scanf("%d",&position);
    if(position>global_count){
        printf("Invalid Postion!\n");
    }
    else{
        if(position ==1){
            Delete_First();
        }
        else if(position== global_count){
            Delete_Last();
        }
        else{
        newnode = head;
        for(i=1;i<position;i++){
            temp = newnode;
            newnode = newnode->link;
        }
        temp->link = newnode->link;
        free(newnode);
        global_count--;
        printf("\nOperation has been successfully finished\n");
     }
    }
}

int main(){
    printf("\nInsertion operation happening.\n");
    head = NULL;
    int resume =1, choice=1,select;
    while(resume){
        newnode = (struct Node *) malloc(sizeof(struct Node));
        printf("Enter the data to be insert in the current node: ");
        scanf("%d",&newnode->data);
        newnode->link = NULL;
        global_count++;
        if(head ==NULL)
        {
            head = temp = newnode;
        }
        else{
            temp->link = newnode;
            temp = newnode;
        }
        printf("Wanna Resume this insertion operation ( 0 0r 1 ): ");
        scanf("%d",&resume);
    }
    while(choice){
        printf("1.Display the data items in the nodes of a linked list\n");
        printf("2.Delete the 1st node from the linked list\n");
        printf("3.Delete the last node from the lined list\n");
        printf("4.Delete the Desired Position node\n");
        printf("\n\nEnter the choice (1,2,3,4):");
        scanf("%d",&select);
        if(select ==1){
            Display();
        }
        else if(select ==2){
            Delete_First();
        }
        else if(select ==3){
            Delete_Last();
        }
        else if(select ==4){
            Delete_Desired();
        }
        else{
            printf("\nInvalid option given!\n");
        }
        printf("\nWanna continue above 4 operations(0 0r 1):");
        scanf("%d",&choice);
    }
    return 0;
}