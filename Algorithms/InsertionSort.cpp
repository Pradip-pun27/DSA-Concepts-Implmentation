#include<iostream>
using namespace std;
void InsertionSort(int *Ar,int n){
    int i,j,key;
    for(i=1;i<n;i++){
        j=i-1;
        key=Ar[i];
        while(j>=0 && Ar[j]>key){
            Ar[j+1]=Ar[j];
            j--;
        }
        Ar[j+1]=key;
    }
}
int main() {
    int n,Ar[20];
    cout<<"Enter the Array Size =";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Enter the Array=";
        cin>>Ar[i];
    }
    
    InsertionSort(Ar,n);
    cout<<"Sorted Array is "<<endl;
    for(int i=0;i<n;i++){
        cout<<Ar[i]<<" ";
    }
    return 0;
}