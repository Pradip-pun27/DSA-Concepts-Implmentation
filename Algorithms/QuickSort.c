#include <stdio.h>

void printArray(int *Ar, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", Ar[i]);
    }
    printf("\n");
}

void swap(int *n1, int *n2)
{
    int t;
    t = *n1;
    *n1 = *n2;
    *n2 = t;
}

int partitionFunc(int *Ar, int low, int high)
{
    int pivot = Ar[low];
    int i = low + 1;
    int j = high;
    do
    {
        while (i <= high && Ar[i] <= pivot)
        {
            i++;
        }
        while (j >= low && Ar[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(Ar + i, Ar + j);
        }
    } while (i < j);

    swap(Ar + low, Ar + j); // Ar+low is same as &Ar[low]
    return j;
}

void QuickSort(int *Ar, int low, int high)
{
    if (low < high)
    {
        int partitionIdx = partitionFunc(Ar, low, high);
        QuickSort(Ar, low, partitionIdx - 1);
        QuickSort(Ar, partitionIdx + 1, high);
    }
}

int main()
{
    int A[] = {8, 9, 4, 1, 7, 10,91,16};
    int n = 8;
    printArray(A, n);
    QuickSort(A, 0, n - 1);
    printf("The Sorted Array is \n");
    printArray(A, n);
    return 0;
}