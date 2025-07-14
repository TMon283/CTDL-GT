#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int size;
    int rear;
    int maxSize;
} queue;

void initQueue(queue *q,int maxSize){
    q->data=(int *)malloc(maxSize*sizeof(int));
    q->front=0;
    q->rear=-1;
    q->size=0;
    q->maxSize=maxSize;
}

int isEmpty(queue *q) {
    return q->size==0;
}

int isFull(queue *q) {
    return q->size==q->maxSize;
}

int main(void) {
    queue q;
    initQueue(&q,5);
    return 0;
}