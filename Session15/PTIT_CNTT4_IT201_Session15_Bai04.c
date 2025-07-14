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

void displayQueue(Queue q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d\n", q.array[i]);
    }
}

int main() {
    Queue queue1 = createQueue(5);
    displayQueue(queue1);

    Queue queue2 = createQueue(5);
    enqueue(&queue2, 1);
    enqueue(&queue2, 2);
    enqueue(&queue2, 5);
    displayQueue(queue2);

    free(queue1.array);
    free(queue2.array);
    return 0;
}