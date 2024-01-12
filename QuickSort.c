//Quick sort with first element as pivot//

#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

void print_array(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l, j = h;
    
    while(i<j)
    {
        while(arr[i]<pivot)
        {
            i++;
        }
        
        while(arr[j]>pivot)
        {
            j--;
        }
        
        if(i<=j)
        {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    return i;
}

void QuickSort(int arr[], int l, int h)
{
    if (l<h)
    {
        int j = partition(arr, l, h);
        QuickSort(arr, l, j-1);
        QuickSort(arr, j, h);
    }
}

int main()
{
    int A[] = {84, 687, 19, 134, 56, 789};
    int size = sizeof(A)/sizeof(A[0]);
    
    printf("The unsorted array is:\n");
    print_array(A, size);
    
    QuickSort(A, 0, size-1);
    
    printf("The sorted array is:\n");
    print_array(A, size);
    
    return 0;
}
