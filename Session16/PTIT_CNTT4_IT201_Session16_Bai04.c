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

int viewFront(Queue* q) {
    if (q->front == NULL) {
        printf("empty queue\n");
        return -1;
    }
    printf("%d\n", q->front->data);
    return q->front->data;
}

int main() {
    Queue* q1 = createQueue();
    viewFront(q1);
    Queue* q2 = createQueue();
    enqueue(q2, 1);
    enqueue(q2, 2);
    enqueue(q2, 5);
    viewFront(q2);
    free(q1);
    free(q2);
    return 0;
}