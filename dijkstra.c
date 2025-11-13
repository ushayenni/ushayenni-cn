#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

int minDistance(int dist[], bool visited[], int V) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1)
        return;
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

void dijkstra(int graph[20][20], int V, int src) {
    int dist[20];
    bool visited[20];
    int parent[20];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\nVertex\t\tDistance\tPath");
    for (int i = 0; i < V; i++) {
        printf("\n%d\t\t", i);
        if (dist[i] == INT_MAX)
            printf("INF\t\tNo path");
        else {
            printf("%d\t\t%d", dist[i], src);
            printPath(parent, i);
        }
    }
}

int main() {
    int graph[20][20];
    int V, src;

    printf("Enter number of vertices (max 20): ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (use 0 for no edge):\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex (0 to %d): ", V - 1);
    scanf("%d", &src);

    dijkstra(graph, V, src);

    return 0;
}
