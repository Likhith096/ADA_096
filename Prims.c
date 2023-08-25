#include <stdio.h>

int cost[10][10], vt[10], et[10][10], vis[10], j, n;
int sum = 0;
int x = 1;
int e = 0;

void prims()
{
   int s, min, m, k, u, v;
   vt[x] = 1;
   vis[x] = 1;
   for (s = 1; s < n; s++)
   {
      j = x;
      min = 999;
      while (j > 0)
      {
         k = vt[j];
         for (m = 2; m <= n; m++)
         {
            if (vis[m] == 0)
            {
               if (cost[k][m] < min)
               {
                  min = cost[k][m];
                  u = k;
                  v = m;
               }
            }
         }
         j--;
      }
      vt[++x] = v;
      et[s][0] = u;
      et[s][1] = v;
      e++;
      vis[v] = 1;
      sum = sum + min;
   }
   printf("edges of spanning tree\n");
   for (int i = 1; i <= e; i++)
   {
      printf("%d,%d\t", et[i][0], et[i][1]);
   }
   printf("weight=%d\n", sum);
}

void main()
{
   int i;
   printf("enter the number of vertices\n");
   scanf("%d", &n);
   printf("enter the cost adjacency matrix\n");
   for (i = 1; i <= n; i++)
   {
      for (j = 1; j <= n; j++)
      {
         scanf("%d", &cost[i][j]);
      }
      vis[i] = 0;
   }
   prims();
}


// 4 vertices
// Adj matrix with cost :-
// 0 1 3 4
// 1 0 2 999
// 3 2 0 5
// 4 999 5 0