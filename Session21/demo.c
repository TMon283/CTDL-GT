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

void DFSUtil(Graph* graph, int src, int* visited) {
    printf("%d ", src);
    visited[src] = 1;
    for (int i = 0; i < graph->V; i++) {
        if (graph->matrix[src][i] == 1 && visited[i] == 0) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(Graph *graph, int src) {
    int *visited = (int*)malloc(graph->V * sizeof(int));
    printf("Bat dau duyet tu dinh %d ", src);
    DFSUtil(graph, src, visited);
    printf("\n");
    free(visited);
}

typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
} Queue;

Queue *createQueue(int capacity) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->arr = (int*)malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

void enqueue(Queue *queue, int vertex) {
    if (queue->rear == queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = vertex;
}

int isEmpty(Queue *queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}

int dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        return queue->arr[queue->front];
    }
    return -1;
}

void BFS(Graph *graph, int src) {
    int *visited = (int*)calloc(graph->V, sizeof(int));
    Queue *queue = createQueue(graph->V);
    enqueue(queue, src);
    visited[src] = 1;
    printf("Bat dau duyet BFS tu dinh %d ", src);
    while (!isEmpty(queue)) {
        int vertex = dequeue(queue);
        printf("%d ", vertex);
        for (int i = 0; i < graph->V; i++) {
            if (graph->matrix[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
    free(visited);
    free(queue->arr);
    free(queue);
}

int main() {
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 3);
    addEdge(graph, 1, 2);

    printGraph(graph);
    printf("\n");

    DFS(graph, 0);
    BFS(graph, 0);

    for (int i = 0; i < graph->V; i++) {
        free(graph->matrix[i]);
    }
    free(graph->matrix);
    free(graph);

    return 0;
}
