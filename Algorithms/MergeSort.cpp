#include<iostream>
using namespace std;

void Merge(int *A, int l, int mid, int r){
    int i=l,j=mid+1,k=0;
    int t[100];

    while(i<=mid && j<=r){
        if(A[i] < A[j]){
            t[k++]=A[i++];
        }
        else{
            t[k++]=A[j++];
        }
    }
    
    while(i<=mid){
        t[k++]=A[i++];
    }
    while(j<=r){
        t[k++]=A[j++];
    }

    for(i=l,k=0;i<=r;i++,k++){
        A[i]=t[k];
    }
}

void MergeSort(int *A, int l, int r){
    if(l>=r){
        return; //Base Case
    }
    int mid=(l+r)/2;
    MergeSort(A,l,mid); //Left
    MergeSort(A,mid+1,r); //Right

    Merge(A,l,mid,r); // Combine
}

int main() {
    int A[6]={6,7,8,3,2,1},i,l=0,h=5;
    MergeSort(A,l,h);
    for(i=0;i<6;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}