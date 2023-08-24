#include <stdio.h>
int a[10][10]; // Adjacency Matrix
int find(int v, int parent[10])//used to find the representative (parent) of a given vertex in a disjoint-set
{
  while (parent[v] != v)
  {
    v = parent[v];
  }
  return v;
}
void union1(int i, int j, int parent[10])//connects two sets by updating the parent of one representative to point to the other representative.
{
  if (i < j)
    parent[j] = i;
  else
    parent[i] = j;
}
void kruskal(int n)
{
  int count, k, min, sum, i, j, t[10][10], u, v, parent[10];
  count = 0; //To keep track of number of edges in MST
  k = 0;
  sum = 0; //Total sum will be minimum spanning weight
  for (i = 0; i < n; i++)
    parent[i] = i; //Initialize the parents
  while (count != n - 1)
  {
    min = 999;
    // Find the edge with the minimum weight (min) in the graph's adjacency matrix.
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {

        if (a[i][j] < min && a[i][j] != 0) 
        {
          min = a[i][j];
          u = i; //u,v -> vertices of minimum edge
          v = j;
        }
      }
    }
    i = find(u, parent); //Finding parents of u,v
    j = find(v, parent);
    //If the parents of u and v are different, it means adding the edge u-v does not create a cycle. 
    if (i != j)
    {
      union1(i, j, parent);
      t[k][0] = u;
      t[k][1] = v;
      k++;
      count++;
      sum = sum + a[u][v];
    }
    a[u][v] = a[v][u] = 999; //To ensure that this minimum edge will be not chosen again
  }
  if (count == n - 1)
  {
    printf("Spanning tree\n");
    for (i = 0; i < n - 1; i++)
    {
      printf("%d %d\n", t[i][0], t[i][1]);
    }
    printf("Cost of spanning tree=%d\n", sum);
  }
  else
    printf("Spanning tree does not exist\n");
}
void main()
{
  int n, i, j;
  printf("Enter the number of nodes:\n");
  scanf("%d", &n);
  printf("Enter the adjacency matrix:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
  kruskal(n);
}