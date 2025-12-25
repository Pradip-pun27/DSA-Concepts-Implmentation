#include<iostream>
using namespace std;
void TOH(int n, char S, char I, char D){
    if(n>0){
        TOH(n-1,S,D,I);
        printf("Move a Disc from %c to %c\n",S,D);
        TOH(n-1,I,S,D);
    }
}
int main() {
    int num;
    printf("Enter the size of a disc: ");
    scanf("%d",&num);
    TOH(num,'S','I','D');
    return 0;
}