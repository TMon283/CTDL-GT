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

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int main() {
    Queue* q = createQueue();
    if (q->front == NULL && q->rear == NULL) {
        printf("Hang doi rong\n");
    } else {
        printf("Hang doi da duoc tao\n");
    }
    free(q);
    return 0;
}