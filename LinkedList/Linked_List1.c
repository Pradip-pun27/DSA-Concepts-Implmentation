#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head, *NewNode, *temp;
int global_count=0;

void Print(){
  // For accessing or traversing the data items in the nodes of a linked list  
  int count =0;
  temp =head;
  while(temp!=0){
    count++;
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n%d items has been displayed.\n",count);  
}

void Insert_First(){
NewNode = (struct node *)malloc(sizeof(struct node));
printf("Enter the data to be inserted: ");
scanf("%d",&NewNode->data);
global_count++;
NewNode->next = head;
head = NewNode;
printf("Operation has been successfully done.\n\n");
}

void Insert_Last(){
NewNode = (struct node *) malloc(sizeof(struct node));
printf("Enter the data to be inserted: ");
scanf("%d",&NewNode->data);
global_count++;
NewNode->next = 0;
temp = head;
while(temp->next !=0){
  temp = temp->next;
}
temp->next = NewNode;
printf("Operation has been successfully done.\n\n");
}

void Insert_Desired(){
  int position,i=1;
  printf("Enter the position : ");
  scanf("%d",&position);
  if(position > global_count){
    printf("\nInvalid Position!\n");
  }  
  else{
    NewNode = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while(i<position-1){
      temp = temp->next;
      i++;
    }
    printf("Enter the data to be inserted : ");
    scanf("%d",&NewNode->data);
    global_count++;
    NewNode->next = temp->next;
    temp->next= NewNode;
    printf("Operation has been successfully done.\n");
  }
}

int main(){
    int choice=1,select;
    head =0;
    while(choice){
    NewNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data to  be inserted : ");
    scanf("%d",&NewNode->data);
    global_count++;
    NewNode->next =0;
    if(head == 0){
        temp = head = NewNode;
    }

    else{
        temp->next = NewNode;
        temp = NewNode;
    }
    printf("Wanna continue?(0 or 1):");
    scanf("%d",&choice);
} 
printf("1.Display\n2.Insert into the 1st position\n3.Insert into the last position\n4.Insert at desired position\n\n");
do{
printf("Enter choice(1,2,3,4):");
scanf("%d",&select);
switch(select){
  case 1:
    Print(); break;
  case 2:
    Insert_First(); break;
  case 3:
    Insert_Last(); break;
  case 4:
    Insert_Desired(); break;
  case 5:
    free(NewNode);
    break;
  default:
    printf("Invalid Option given!\n");

}
}while(select!=5);

return 0;
}