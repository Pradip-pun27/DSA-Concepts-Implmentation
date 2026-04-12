#include<iostream>
using namespace std;
int A[6]={4,3,1,2,3,7},n=6;
int ArraySum(int i){
    if(i==n){
        return 0;
    }
    else{
        return A[i]+ArraySum(i+1);
    }
}
int main() {
    int i=0,sum=0;
    cout<<"Total Sum of Array is (By Recursion) "<<ArraySum(0)<<endl;
    while(i<n){
        sum+=A[i++];
    }
    cout<<"By Accumulation Sum is "<<sum<<endl;
    return 0;
}