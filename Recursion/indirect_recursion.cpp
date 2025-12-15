#include<iostream>
using namespace std;
int func2(int &num);
int func1(int &n){
    if(n==0){
        return 1;
    }
    else{
        --n;
        return func2(n);
    }
}

int func2(int &num){
    return func1(num);
}
int main() {
    int  number = 111;
    cout<<"The last answer is "<<func1(number)<<endl; //Answer will always be 1 no matter what the value of number is
    return 0;
}