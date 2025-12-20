#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *link;
};
struct Node *top= NULL, *newnode, *temp;
void Push(int num){
    newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data = num;
    newnode->link = top;
    top = newnode;
    printf("Push operation has been successfully coompeleted.\n");
}

int Peek(){
    if(top == NULL){
        printf("Stack is empty!\n");
    }
    else{
        return top->data;
    }
}

void Pop(){
    if(top == NULL){
        printf("Stack is Empty\n");
    }
    else{
        temp = top;
        printf("Popped data item is %d\n",temp->data);
        top = top->link;
        free(temp);
    }
}

void Display(){
    if(top == NULL){
        printf("Stack is empty!\n");
    }
    else{
        temp = top;
        printf("The data items in the stack are show below\n");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp = temp->link;
        }
    }
}

int main() {
    int choice =1;
    while(choice){
        int select,num;
        printf("\n----------------Stack_Operations----------------\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n");
        printf("Enter yrs choice :");
        scanf("%d",&select);
        if(select ==1){
            printf("Enter the data u wanna push: ");
            scanf("%d",&num);
            Push(num);
        }
        else if(select ==2){
            Pop();
        }
        else if(select ==3){
            printf("The data item at the peek of stack is %d\n",Peek());
        }
        else if(select ==4){
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