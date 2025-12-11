#include<iostream>
#include<string>
void push();
void pop();
void display();
int choice,n,top,item,i,stack[10];
using namespace std;
int main(){
    top =-1;
    printf("Enter the size of a stack :");
    cin>>n;
    cout<<"1.Push\n2.Pop\n3.Display"<<endl;
    do{
        cout<<"Enter yours choice:";
        cin>>choice;
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
            cout<<"Invalid option given!"<<endl;
        }
    }while(choice!=3);
return 0;
}

void push(){
    if(top==n-1){
        cout<<"Stack Overflow!"<<endl;
    }
    else{
        cout<<"Enter the data to be inserted: ";
        cin>>item;
        top+=1;
        stack[top]=item;
    }
}

void pop(){
    if(top==-1){
        cout<<"Stack is Empty!"<<endl;
    }
    else{
        cout<<"The current item(data) in the top of stack is :"<<stack[top]<<endl;;
        top--;
    }
}
void display(){
    if(top>=0){
        cout<<"items are \n";
        for(i=top;i>=0;i--){
            cout<<stack[i]<<endl;;
        }
    }
    else{
        cout<<"The Stack is Empty!"<<endl;
    }
}