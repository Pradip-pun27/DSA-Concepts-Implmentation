#include<iostream>
using namespace std;

// Global variables for Queue implementation
int f=-1,r=-1,Queue[5];
/* f = front pointer (points to first element)
   r = rear pointer (points to last element)
   Queue[5] = array to store queue elements
   Initially both f and r are -1 (empty queue)
*/

 // Enqueue Operation: Insert an element at the rear of the queue
 
void Enqueue(){
    int item;
    
    // Check if queue is full (rear pointer reached last index)
    if(r == 5-1){
        cout<<"The Queue is full."<<endl;
        return; // Exit function without inserting, prevents overflow
    }
    
    // Check if queue is empty (first time insertion)
    // If empty, set front pointer to 0
    if(f==-1){
        f=0; // Set front to 0 for the first element insertion
    }
    
    r++; // Move rear pointer to next position
    cout<<"Enter the item to be inserted: ";
    cin>>item;
    Queue[r]= item; // Insert element at rear position
}


 // Dequeue Operation: Remove an element from the front of the queue
 
void Dequeue(){
    // Check if queue is empty using two conditions:
    // f==-1 (never had element) OR f>r (all elements removed)
    if(f==-1 || f>r){
        cout<<"Queue is Empty."<<endl;
        return; // Exit function, cannot dequeue from empty queue
    }
    
    cout<<"Deleted item is "<<Queue[f]<<endl;
    f++; // Move front pointer forward (effectively removes element)
    
    // Check if queue became completely empty after dequeue
    if(f>r){
        f=r=-1; // Reset both pointers to -1 for next fresh insertion
    }
}


  // Peek Operation: View the front element without removing it
 
void Peek(){
    // Check if queue is empty
    if(f==-1 || f>r){
        cout<<"The Queue is Empty!"<<endl;
        return; // Exit function, cannot peek empty queue
    }
    
    // Display the front element without modifying pointers
    cout<<"The item at the front is: "<<Queue[f]<<endl;
}


  // Display Operation: Show all elements currently in the queue
 
void Display(){
    // Check if queue is empty
    if(f==-1){
        cout<<"Queue is Empty!"<<endl;
        return; // Exit function, nothing to display
    }
    
    // Loop from front (f) to rear (r) and print all elements
    for(int i=f;i<=r;i++){
        cout<<Queue[i]<<" ";
    }
    cout<<endl; // Add newline for better formatting
}

int main() {
    char choice;
    
    do{
        // Display menu options
        cout<<"\na.Enqueue\t b.Dequeue\t c.Display\t d.Peek\t e.exit \n"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        
        // Switch statement to handle user choice
        switch(choice){
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
                cout<<"Exiting..."<<endl;
                break;
            default:
                cout<<"Invalid choice given!"<<endl;
        }
    }while(choice!='e'); // Loop until user chooses exit
    
    return 0;
}