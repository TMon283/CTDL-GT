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
        printf("Hang doi da day, khong the them %d\n", value);
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}

int main() {
    int capacity = 5;
    Queue myQueue = createQueue(capacity);
    int value;
    for (int i = 0; i < 5; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        enqueue(&myQueue, value);
    }

    printf("Cac phan tu trong hang doi:\n");
    for (int i = myQueue.front; i <= myQueue.rear; i++) {
        printf("%d ", myQueue.array[i]);
    }

    free(myQueue.array);
    return 0;
}