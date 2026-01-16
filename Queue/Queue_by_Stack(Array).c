#include<stdio.h>
#define N 5
int Stack1[N], Stack2[N],top1=-1,top2=-1,count=0;

void push1(int data){
    if(top1 == N-1){
        printf("Stack1 is Full!\n");
    }
    else{
        top1++;
        Stack1[top1]=data;
    }
}

void push2(int data){
    if(top2==N-1){
        printf("The stack2 is Overflow!\n");
    }
    else{
        top2++;
        Stack2[top2]=data;
    }
}

int pop1(){
    int pop_item = Stack1[top1];
    top1--;
    return pop_item;
}


int pop2(){
    int pop_item= Stack2[top2];
    top2--;
    return pop_item;
}

void Enqueue(int x){
    push1(x);
    count++;
}

void Dequeue(){
    int i;
    if(top1==-1 && top2==-1){
        printf("Queue is Empty!\n");
    }
    else{
        for(i=0;i<count;i++){
        push2(pop1());
        }
        printf("Popped Item is %d",pop2());
        count--;
        for(i=0;i<count;i++){
            push1(pop2());
        }
    }
}

int Peek(){
    return Stack1[0];
}

void Display(){
    int i;
    for(i=0;i<=top1;i++){
        printf("%d ",Stack1[i]);
    }
}
int main() {
    int choice=1;
      while(choice){
        int select,num;
        printf("----------------------Queue_Implementation_Using_Stack----------------------\n");
        printf("1.Push\n2.Pop\n3.Peek\n4.Display\n");
        printf("Enter yrs choice :");
        scanf("%d",&select);
        if(select ==1){
            printf("Enter the data u wanna push: ");
            scanf("%d",&num);
            Enqueue(num);
        }
        else if(select ==2){
           Dequeue();
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