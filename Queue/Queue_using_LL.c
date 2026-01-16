#include<stdio.h>
#include<stdlib.h>
struct Node {
int data;
    struct Node *next;
};
struct Node *front = NULL, *rear = NULL, *newnode, *temp;

void Enqueue(int num){
    newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = num;
    newnode->next = NULL;
    if(front == NULL && rear == NULL){
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
    }
    printf("Enqueue operation is done at the rear of the Queue.\n");
}

void Display(){
    if(front == NULL && rear == NULL){
        printf("Queue is NULL\n");
    }
    else{
        printf("The data items of the Queue are \n");
        temp = front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->next;
        }
    }
}

void Dequeue(){
    if(front == NULL && rear == NULL){
        printf("Queue is NULL\n");
    }
    else{
        temp = front;
        front = front->next;
        free(temp);
        printf("Dequeue operation is done from the front of the Queue.\n");
    }
}
int main() {
      int choice =1;
    while(choice){
        int select,num;
        printf("\n----------------Queue_Operations----------------\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n");
        printf("Enter yrs choice :");
        scanf("%d",&select);
        if(select ==1){
            printf("Enter the data u wanna Enqueue in the rear: ");
            scanf("%d",&num);
            Enqueue(num);
        }
        else if(select ==2){
            Dequeue();
        }
        else if(select ==3){
            Display();
        }
        else{
            printf("Invalid Option Given!\n");
        }
        printf("\nWanna continue (0 0r 1):");
        scanf("%d",&choice);
    }
 return 0;
}