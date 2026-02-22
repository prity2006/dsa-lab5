#include <stdio.h>
#include <limits.h>

#define V 6  // number of vertices

// Function to find the vertex with minimum distance
int minDistance(int dist[], int visited[]) {
    int min = INT_MAX, min_index = -1;

    for(int v = 0; v < V; v++) {
        if(!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the shortest path
void printPath(int parent[], int j) {
    if(parent[j] == -1) {
        printf("%d", j);
        return;
    }
    printPath(parent, parent[j]);
    printf(" -> %d", j);
}

// Function to print distances and paths
void printSolution(int dist[], int parent[], int src) {
    printf("Vertex\tDistance from Source\tPath\n");
    for(int i = 0; i < V; i++) {
        if(dist[i] == INT_MAX) {
            printf("%d\tINF\t\t\tNo path\n", i);
        } else {
            printf("%d\t%d\t\t\t", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

// Dijkstra’s algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];     // shortest distance from source
    int visited[V];  // visited vertices
    int parent[V];   // store shortest path tree

    for(int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for(int v = 0; v < V; v++) {
            if(!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, parent, src);
}

int main() {
    // Weighted graph as adjacency matrix
    int graph[V][V] = {
        {0, 4, 2, 0, 0, 0},
        {4, 0, 1, 5, 0, 0},
        {2, 1, 0, 8, 10, 0},
        {0, 5, 8, 0, 2, 6},
        {0, 0, 10, 2, 0, 3},
        {0, 0, 0, 6, 3, 0}
    };

    int source = 0;
    dijkstra(graph, source);

    return 0;
}