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
    if (q->rear < q->capacity - 1) {
        q->rear++;
        q->array[q->rear] = value;
    }
}

int isIncreasingByOne(Queue q) {
    for (int i = q.front; i < q.rear; i++) {
        if (q.array[i + 1] - q.array[i] != 1)
            return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    Queue q = createQueue(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    if (isIncreasingByOne(q))
        printf("True\n");
    else
        printf("False\n");

    free(q.array);
    return 0;
}