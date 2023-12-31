#include<stdio.h>
int graph[20][20];
void DFS(int i,int vis[],int n)
{
    int j;
    printf("%d ",i);
    vis[i]=1;
    for(j=0;j<n;j++)
    {
        if(graph[i][j]==1 && vis[j]==0)
        {
            DFS(j,vis,n);
        }
    }
}
int main()
{
    int n,i,j,top=-1;
    printf("Enter the number of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix representing the graph:\n");
    
    int vis[n],st[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
    }
    DFS(0,vis,n);
    int isConnected = 1;
    for(int i=0;i<n;i++)
    {
        if(vis[i]==0){
            isConnected=0;
            break;
        }
    }
    if(isConnected)
        printf("\nThe Graph is Connected\n");
    else
        printf("\nThe Graph is not Connected\n");
    return 0;
}

/*
Number of vertices : 6
Adj Matrix:-
0 1 1 0 0 0
0 0 0 1 1 0
0 0 0 0 0 1
0 1 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0
*/