#include<stdio.h>

void PrintArray(int *ar, int n){
    for(int i =0;i<n;i++){
        printf("%d ",*(ar+i));
    }
    printf("\n");
}

void bubbleSort(int *ar, int n){
    int t, isSorted;
    for(int i=0; i<n-1; i++){
        isSorted =1;
        printf("Working in the i = %d\n",i);
        for(int j=0;j<n-1-i; j++){
            if(ar[j] > ar[j+1]){
                t = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = t;
                isSorted= 0;
            }
        }
        if(isSorted){
            return ;
        }
    }
}
int main() {
    // int A[] = {1,2,3,4};
       int A[] = {1,9,7,4};
    int size = 4;
    PrintArray(A, size);
    bubbleSort(A, size);
    PrintArray(A, size);
 return 0;
}