#include<iostream>
using namespace std;
int Stair(int n){
    if(n==1 || n==2){ return n;}

    int totalSum=Stair(n-1) + Stair(n-2);
    return totalSum;
}
int main() {
    int n;
    cout<<"Enter the Number of Stair's step: ";
    cin>>n;
    cout<<"Total Ways : "<<Stair(n)<<endl;
    return 0;
}