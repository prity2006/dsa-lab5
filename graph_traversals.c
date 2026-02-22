#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjLists[MAX];
    int visited[MAX];
} Graph;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void initGraph(Graph* graph) {
    for (int i = 0; i < MAX; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFS(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;
        if (graph->visited[connectedVertex] == 0) {
            DFS(graph, connectedVertex);
        }
        adjList = adjList->next;
    }
}

int main() {
    Graph graph;
    initGraph(&graph);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 4);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    printf("DFS Traversal starting from vertex 0:\n");
    DFS(&graph, 0);

    return 0;
}