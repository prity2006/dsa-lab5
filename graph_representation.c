#include <stdio.h>
#define MAX 5

int graph[MAX][MAX] = {0};

void addEdge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;  // Undirected graph
}

void printGraph(int vertices) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 5;

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    printGraph(vertices);
    return 0;
}