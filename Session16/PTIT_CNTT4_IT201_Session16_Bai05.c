#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Node* createNode(int value) {
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

void enqueue(Queue* q, int value) {
    Node* newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node* temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
}

void printQueue(Queue* q) {
    Node* current = q->front;
    printf("queue = {\n  front->");
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("  rear->");
    if (q->rear != NULL)
        printf("%d->NULL\n", q->rear->data);
    else
        printf("NULL\n");
    printf("}\n");
}

int main() {
    Queue* q1 = createQueue();
    dequeue(q1);
    Queue* q2 = createQueue();
    enqueue(q2, 1);
    enqueue(q2, 2);
    enqueue(q2, 5);
    dequeue(q2);
    printQueue(q2);
    free(q1);
    free(q2);
    return 0;
}