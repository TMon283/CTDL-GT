#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

Queue createQueue(int capacity) {
    Queue q;
    q.array = (int *)malloc(capacity * sizeof(int));
    q.front = 0;
    q.rear = -1;
    q.capacity = capacity;
    return q;
}

void enqueue(Queue *q, int value) {
    if (q->rear == q->capacity - 1) {
        printf("Hang doi da day\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}

int isEmpty(Queue q) {
    return q.rear < q.front;
}

int main() {
    Queue queue1 = createQueue(5);
    printf("Queue 1 rong? %s\n", isEmpty(queue1) ? "true" : "false");

    Queue queue2 = createQueue(5);
    enqueue(&queue2, 1);
    enqueue(&queue2, 2);
    enqueue(&queue2, 5);
    printf("Queue 2 rong? %s\n", isEmpty(queue2) ? "true" : "false");

    free(queue1.array);
    free(queue2.array);
    return 0;
}