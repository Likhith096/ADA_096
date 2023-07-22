// 1. Sort a given set of N integer elements using Merge Sort technique and compute its time
//  taken for different n values.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int A[100];

void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
        B[k++] = A[i];
    for (; j <= h; j++)
        B[k++] = A[j];

    for (i = l; i <= h; i++)
        A[i] = B[i];
}
void MergeSort(int A[], int l, int h)
{
    if (l < h)
    {
        int mid = l + (h - l) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        Merge(A, l, mid, h);
    }
}


int main()
{
    clock_t start, end;
    start = clock();
    int n;
    printf("Enter the array size\n");
    scanf("%d", &n);
    printf("Enter the Elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d",&A[i]);
    MergeSort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    end = clock();


    float duration = ((float)(end - start)) / CLOCKS_PER_SEC;
     
    printf("Time taken to execute in seconds : %f", duration);
    return 0;
}