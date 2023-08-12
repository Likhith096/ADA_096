#include <stdio.h>
#define INFINITY 999
#define MAX 10

void Dijkstra(int Graph[MAX][MAX], int n, int start)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;

    // Creating cost matrix
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (Graph[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = Graph[i][j];
        }
    }

    for (i = 1; i <= n; i++)
    {
        distance[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count <= n - 1)
    {
        mindistance = INFINITY;

        for (i = 1; i <= n; i++)
        {
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }

        visited[nextnode] = 1;
        for (i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
            }
        }
        count++;
    }

    // Printing the distance
    for (i = 1; i <= n; i++)
    {
        if (i != start)
        {
            printf("\nDistance from source to %d: %d", i, distance[i]);
        }
    }
}

int main()
{
    int Graph[MAX][MAX], i, j, n, u;
    printf("Dijkstra's algorithm\n");
    printf("========================\n");

    printf("Enter the no. of vertices:\n");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &Graph[i][j]);
        }
    }

    Dijkstra(Graph, n, 1);

    return 0;
}
/*
0 25 100 35 999 999
999 0 999 27 14 999
999 999 0 50 999 999 
999 999 999 0 29 999
999 999 999 999 0 21
999 999 48 999 999 0
*/