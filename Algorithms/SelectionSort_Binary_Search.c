#include<stdio.h>

void Print_Array(int *Ar, int n){
    for(int i=0;i<n;i++){
        printf("%d ",*(Ar+i));
    }
}

void Selection_Sort(int *Ar, int n){
    int temp,min_idx,i,j;
    for(i=0;i<n-1;i++){
        min_idx = i;
        for(j=i+1;j<n;j++){
            if(Ar[j] < Ar[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx !=i){
            temp = Ar[i];
            Ar[i]= Ar[min_idx];
            Ar[min_idx] = temp;
        }
    }
}

void Binary_Search(int search_item, int n, int *Ar){
    int start = 0, end = n-1, mid, flag =0;
        while(start<=end){
        mid = (start + end)/2;
        if(search_item == Ar[mid]){
            printf("The number u were searching is found !\n");
            flag =1;
            break;
        }
        else if(search_item > Ar[mid]){
            start = mid+1; // Look in the right half
        }
        else{
            end = mid-1; // Look in the left half
        }

    }
    if(!flag){
        printf("Sorry item wasn't a/v in the Array.\n");
    }
    
}
int main(){
    int Ar[] = {4,1,7,5,9,3};
    int n=6,search_item; // here n is acting as the size of an Array(Ar);

    // printf("Before sorting : ");
    // Print_Array(Ar,n);
    // printf("\nAfter sorting: ");
    Selection_Sort(Ar,n);
    // Print_Array(Ar,n);
    printf("Enter the item u wanna search within the list (for now in between 1 - 10): ");
    scanf("%d",&search_item);
    Binary_Search(search_item, n, Ar);
    return 0;
}