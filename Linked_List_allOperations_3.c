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
printf("%d nodes were created\n",count_nodes);
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
    printf("Enter the Position of the Node u Wanna remove from the linked list: ");
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

void Insert_First(){
newnode = (struct Node *)malloc(sizeof(struct Node));
printf("Enter the data to be inserted: ");
scanf("%d",&newnode->data);
global_count++;
newnode->link = head;
head = newnode;
printf("Operation has been successfully done.\n\n");
}

void Insert_Last(){
newnode = (struct Node *) malloc(sizeof(struct Node));
printf("Enter the data to be inserted: ");
scanf("%d",&newnode->data);
global_count++;
newnode->link = 0;
temp = head;
while(temp->link !=0){
  temp = temp->link;
}
temp->link = newnode;
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
    newnode = (struct Node *)malloc(sizeof(struct Node));
    temp = head;
    while(i<position-1){
      temp = temp->link;
      i++;
    }
    printf("Enter the data to be inserted : ");
    scanf("%d",&newnode->data);
    global_count++;
    newnode->link = temp->link;
    temp->link= newnode;
    printf("Operation has been successfully done.\n");
  }
}

void Search(){
    int position = 0, flag=0, item;
    temp = head;
    printf("Enter the data item u wanna search (integer number) : ");
    scanf("%d",&item);
    while(temp!=NULL){
        if(item == temp->data){
            flag = 1;
            position++;
            break;

        }
        position++;
        temp = temp->link;
    }
    if(flag){
        printf("%d data item is at  position-%d of node.\n",item,position);
    }
    else{
        printf("%d node isn't found in the linked list.\n",item);
    }
}

int main(){
    printf("\nInsertion operation happening.\n");
    head = NULL;
    int resume =1, choice=1,select;
    while(resume){
        newnode = (struct Node *) malloc(sizeof(struct Node));
        printf("Enter the data to be insert in the current Node: ");
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
        printf("\n----------------------Choose the Options----------------------\n");
        printf("1.Display the data items in the nodes of a linked list\n");
        printf("2.Delete from the 1st Node from the linked list\n");
        printf("3.Delete from the last Node from the lined list\n");
        printf("4.Delete from the Desired Position Node\n");
        printf("5.Insert into the 1st Node from the linked list\n");
        printf("6.Insert into the last Node from the lined list\n");
        printf("7.Insert into the Desired Position Node\n");
        printf("8.Search the data item in the linked list\n");
        printf("\n\nEnter the choice (1,2,3,4,5,6,7,8):");
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
        else if(select ==5){
            Insert_First();
        }
        else if(select ==6){
            Insert_Last();
        }
        else if(select ==7){
            Insert_Desired();
        }
        else if(select ==8){
            Search();
        }
        else{
            printf("\nInvalid option given!\n");
        }
        printf("\nWanna continue above 4 operations(0 0r 1):");
        scanf("%d",&choice);
    }
    return 0;
}