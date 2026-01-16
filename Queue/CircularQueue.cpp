#include<iostream>
int Queue[5],f=-1,r=-1;
using namespace std;
void Enqueue(){
    int item;
    if(f == (r+1)%5){
        cout<<"Queue is FULL"<<endl;
        return;
    }
    if(f==-1){
        f=0;
    }
    cout<<"Enter the item to be inserted : ";
    cin>>item;
    r=(r+1)%5;
    Queue[r]= item;

}

void Dequeue(){
    if(f==-1){
        cout<<"Queue is Empty!"<<endl;
    }
    else if(f == r){
        cout<<"The Dequeued item is "<<Queue[f]<<endl;
        f= r = -1;
    }
    else{
        cout<<"The Dequeued item is "<<Queue[f]<<endl;
        f=(f+1)%5;
    }
}


void Display(){
    int i= f;
    if(f==-1 && r==-1){
        cout<<"Queue is Empty"<<endl;
        return;
    }
    else{
        cout<<"Items in Queue are :";
        while(i!=r){
            cout<<Queue[i]<<" ";
            i=(i+1)%5;
        }
        cout<<Queue[i]<<endl;
    }
}

void Peek() {
        if (f == -1) {
            cout << "The Queue is Empty!" << endl;
            return;
        }
        cout << "The item at the front is: " <<Queue[f] << endl;
    }

int main() {
    char choice;
    
    do {
        cout << "\na.Enqueue\t b.Dequeue\t c.Display\t d.Peek\t e.exit\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 'a':
                Enqueue();
                break;
            case 'b':
                Dequeue();
                break;
            case 'c':
                Display();
                break;
            case 'd':
                Peek();
                break;
            case 'e':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice given!" << endl;
        }
    } while(choice != 'e');
    return 0;
}