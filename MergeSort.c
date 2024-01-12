//Merge Sort//

#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int l, int m, int h) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = h - m;

    int L1[n1], L2[n2];

    for (i = 0; i < n1; i++) {
        L1[i] = arr[l + i];
    }

    for (j = 0; j < n2; j++) {
        L2[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L1[i] <= L2[j]) {
            arr[k++] = L1[i++];
        } else {
            arr[k++] = L2[j++];
        }
    }

    while (i < n1) {
       arr[k++] = L1[i++];
    }

    while (j < n2) {
        arr[k++] = L2[j++];
    }
}

void merge_sort(int arr[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {9, 3, 7, 5, 6, 4, 8, 2};
    int arr_size = sizeof(A) / sizeof(A[0]);

    printf("The unsorted array is: \n");
    print_array(A, arr_size);

    merge_sort(A, 0, arr_size - 1);

    printf("\nSorted array is: \n");
    print_array(A, arr_size);

    return 0;
}
