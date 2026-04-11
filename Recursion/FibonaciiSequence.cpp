#include<iostream>
using namespace std;
int Fibo(int n){
    if(n==1 || n==2){
        return 1;   // For fibo. Sequence to start from 0 write : return n-1 
    }
    else{
        return Fibo(n-1) + Fibo(n-2);
    }
}
int main() {
    int n,i;
    cout<<"Enter the number of terms of Fiboancci Sequence =";
    cin>>n;     // For finding only the one term of a Fibo. Sequence no need to use for loop just use cout<<Fibo(n);
    for(i=1;i<=n;i++){
        cout<<Fibo(i)<<" ";
    }
    return 0;
}