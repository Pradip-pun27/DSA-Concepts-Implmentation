#include<iostream>
using namespace std;
/*
Tail recursion: A recursive function is termed as tail if threr are no pending operations to be performed on return from a recursive call in recursive function.
*/
void printNum(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    printNum(n-1);// This is the last step that will be performed before exiting this recursive function
}
int main() {
    int number = 11;
    printNum(number);
    return 0;
}