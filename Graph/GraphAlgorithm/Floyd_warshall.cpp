#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(int adj[][4],int v)
{
int dist[v][v];
for(int i=0; i<v; i++) 
{
    for(int j=0; j<v; j++)
    {
        dist[i][j]=adj[i][j];
    }
}
for(int k=0; k<v; k++){
    for(int i=0; i<v; i++)
    {
     for(int j=0; j<v; j++) 
     {
         if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
          continue;
          else if(dist[i][k]+dist[k][j]<dist[i][j])
          {
              dist[i][j]=dist[i][k]+dist[k][j];
          }
     }
    }
}
for(int i=1; i<=v; i++)
{
    if(dist[i-1][i-1] < 0)
		{
			cout<<"Negative edge weight cycle is present\n";
			return;
        }
}
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      if (dist[i][j] == INT_MAX)
        printf("%4s", "INT_ MAX");
      else
        printf("%4d", dist[i][j]);
    }
    printf("\n");
  }
  }
int main()
{
    int V=4;
    int graph[4][4]={{0,3,INT_MAX,5},
                     {2,0,INT_MAX,4},
                   {INT_MAX,1,0,INT_MAX},
                   {INT_MAX,INT_MAX,2,0}};
   floyd_warshall(graph,V);
}