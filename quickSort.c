#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int A[100];

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(&A[i], &A[j]);
    } while (i < j);
    swap(&A[l], &A[j]);
    return j;
}

void QuickSort(int A[], int l, int h)
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        QuickSort(A, l, j);
        QuickSort(A, j + 1, h);
    }
}

int main()
{
    clock_t start, end;
    int n;
    printf("Enter the array size\n");
    scanf("%d", &n);
    printf("Enter the Elements\n");
    for (int i = 0; i < n; i++)
        scanf("%d",&A[i]);
    start = clock();
    QuickSort(A, 0,n-1);
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");

    end = clock();
    float duration = ((float)(end - start)) / CLOCKS_PER_SEC;
     
    printf("Time taken to execute in seconds : %f", duration);
    return 0;
}
