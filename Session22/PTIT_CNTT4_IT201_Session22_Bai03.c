#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void convertToAdjList(int matrix[][100], Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                Node* newNode = createNode(j);
                newNode->next = adjList[i];
                adjList[i] = newNode;
            }
        }
    }
}

void printAdjList(Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf(" %d ->", temp->vertex);
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

void freeAdjList(Node* adjList[], int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = adjList[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0 || n >= 100) {
        printf("Invalid input\n");
        return 1;
    }

    int matrix[100][100];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("Edge:\n");
    Node* adjList[100];
    convertToAdjList(matrix, adjList, n);
    printAdjList(adjList, n);
    freeAdjList(adjList, n);

    return 0;
}