#include<stdio.h>
void main()
{
    int i,j,w[10],pft[10],x[10],n,cap;
    printf("Enter the number of items\n");
    scanf("%d",&n);
    printf("enter the weight and profit of each item\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&w[i],&pft[i]);
    }
    printf("enter the knapsack capacity\n");
    scanf("%d",&cap);

    int arr[n + 1][cap + 1]; // Corrected the size of the 'arr' matrix

    for (i = 0; i <= n; i++) // no. of items -> rows
    {
        for (j = 0; j <= cap; j++)// capacity -> cols
        {
            if (i == 0 || j == 0)
                arr[i][j] = 0;
            else if (j < w[i]) // weight is more than capacity -> prev row is taken 
                arr[i][j] = arr[i - 1][j];
            else if (j >= w[i]) // capacity is more than this weight
            {
                if (arr[i - 1][j] >= arr[i - 1][j - w[i]] + pft[i]) // Prev is more then keep it
                    arr[i][j] = arr[i - 1][j];
                else
                    arr[i][j] = arr[i - 1][j - w[i]] + pft[i]; // Added 'else' block
            }
        }
    }
      //output
    printf("\nknapsack table\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=cap;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    //To get the selected items :-
    for(i=n;i>=1;i--)
    {
        if(arr[i][cap]!=arr[i-1][cap])
        {
            x[i]=1;
            cap -= w[i];
        }
        else
        {
            x[i]=0;
        }
    }
    printf("\nitems selected are designated 1\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",x[i]);
    }
}

//Number of items : 4
//Weight and profit :-
// 2 12
// 1 10
// 3 20
// 2 15
// Knapsack capacity : 5