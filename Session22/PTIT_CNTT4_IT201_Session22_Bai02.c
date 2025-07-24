#include<stdio.h>
#include<stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
} Graph;

Graph *createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = (int*)calloc(V, sizeof(int));
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

void printMatrix(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}

void printGraph(Graph *graph) {
    for (int i = 0; i < graph->V; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->V; j++) {
            if (graph->matrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int vertex, edge;
    int firstNode, secondNode;
    printf("Enter number of vertices:");
    scanf("%d", &vertex);
    printf("Enter number of edge:");
    scanf("%d", &edge);
    Graph *graph = createGraph(vertex);
    for (int i = 0; i < edge; i++) {
        printf("First node:");
        scanf("%d", &firstNode);
        printf("Second node:");
        scanf("%d", &secondNode);
        addEdge(graph, firstNode, secondNode);
    }
    printGraph(graph);
    free(graph);
    return 0;
}