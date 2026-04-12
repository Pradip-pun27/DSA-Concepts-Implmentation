#include<iostream>
using namespace std;
int Fact(int n, int Ans){
    if(n==0){
        return Ans;
    }
    else{
        return Fact(n-1, n*Ans);
    }
}
int main() {
    int n;
    cout<<"Enter the Number:";
    cin>>n;
    cout<<"The Factorial of "<<n<<" is "<<Fact(n,1)<<endl;
    return 0;
}