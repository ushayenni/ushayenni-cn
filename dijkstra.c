#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
int minDistance(int dist[], bool visited[], int V)
{
        int min = INT_MAX, min_index = -1;
        for(int i=0;i<V;i++)
        {
                if (!visited[i] && dist[i] <= min)
                {
                        min=dist[i];
                        min_index = i;
                }
        }
        return min_index;
}
void printPath(int parent[], int j)
{
        if (parent[j] == -1) {
                printf("%d",j);
                return;
        }
        printPath(parent, parent[j]);
        printf("-> %d",j);
}
void dijkstra(int graph[20][20], int V, int src)
{
        int dist[20];
        bool visited[20];
        int parent[20];
        for (int i=0;i<V;i++)
        {
                dist[i]=INT_MAX;
                visited[i]=false;
                parent[i] = -1;
        }
        dist[src] = 0;
        for(int count = 0;count<V-1;count++)
        {
                int u=minDistance(dist,visited,V);
                visited[u]=true;
                for(int v=0;v<V;v++)
                {
                        if(!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                        {
                                dist[v] = dist[u] + graph[u][v];
                                parent[v] = u;
                        }
                }
        }
