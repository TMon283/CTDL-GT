#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node *graph[], int u, int v) {
    Node *nodeV = createNode(v);
    nodeV->next = graph[u];
    graph[u] = nodeV;

    Node *nodeU = createNode(u);
    nodeU->next = graph[v];
    graph[v] = nodeU;
}

void printGraph(Node *graph[], int V) {
    printf("Danh sach ke cua do thi:\n");
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        Node *temp = graph[i];
        while (temp != NULL) {
            printf("%d->", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

}
int main() {
    int V = 3;
    Node *graph[V];
    for (int i = 0; i < V; i++) {
        graph[i] = NULL;
    }
    addEdge(graph, 1, 2);
    printGraph(graph, V);
    return 0;
}