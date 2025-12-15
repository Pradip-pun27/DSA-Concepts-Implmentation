#include<iostream>
using namespace std;
int GCD(int a, int b){
    if(b!=0){
        return GCD(b,a%b);
    }
    else{
        return a; // returning the gcd of 2 numbers: a and b
    }
}
int main() {
    int n1,n2;
    cout<<"Enter any 2 numbers: ";
    cin>>n1>>n2;
    cout<<"The GCD or HCF of "<<n1<<" and "<<n2<<" is "<<GCD(n1,n2)<<endl;
    return 0;
}