#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct queue {
    Node* front;
    Node* rear;
} Queue;

Node* createNode() {
    int value;
    printf("Nhap gia tri: ");
    scanf("%d", &value);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q) {
    Node* newNode = createNode();

    if (q->front == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void printQueue(Queue* q) {
    printf("queue = {\n");

    printf("front -> ");
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    printf("rear -> ");
    if (q->rear != NULL)
        printf("%d -> NULL\n", q->rear->data);
    else
        printf("NULL\n");

    printf("}\n");
}

int main() {
    Queue* q = createQueue();
    int n;
    printf("Nhap so luong phan tu trong hang doi: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        enqueue(q);
    }
    printQueue(q);
    free(q);
    return 0;
}