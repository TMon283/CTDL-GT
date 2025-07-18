#include<stdio.h>
#include<stdlib.h>

typedef struct Call {
    char numberPhone[10];
    int time;
} Call;

typedef struct Stack {
    Call* calls;
    int top;
    int capacity;
}Stack;

typedef struct Queue {
    Call* calls;
    int front;
    int rear;
    int capacity;
} Queue;

Stack *createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->calls = (Call*)malloc(sizeof(Call) * stack->capacity);
    return stack;
}

Queue *createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->calls = (Call*)malloc(sizeof(Call) * queue->capacity);
    return queue;
}

int isStackFull(Stack* stack) {
    if(stack->top == stack->capacity - 1) {
        return 1;
    }
    return 0;
}

int isQueueFull(Queue* queue) {
    if(queue->rear == queue->capacity - 1) {
        return 1;
    }
    return 0;
}

void push(Stack *stack, Call call) {
    if(isStackFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->calls[++stack->top] = call;
}

void showHistoryCall(Queue *queue) {
    if (queue->front > queue->rear) {
        printf("Queue empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("Phone number: %s ", queue->calls[i].numberPhone);
        printf("Time: %d\n", queue->calls[i].time);
    }
}

int isStackEmpty(Stack* stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

Call* pop(Stack *stack) {
    if(isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    }
    Call* call = &stack->calls[stack->top];
    stack->top--;
    return call;
}

void enqueue(Queue* queue, Call call) {
    if(isQueueFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->calls[++queue->rear] = call;
}

int main() {
    int choice;
    Stack* backStack = createStack(10);
    Stack* forwardStack = createStack(10);
    Queue* historyCall = createQueue(10);
    do {
        printf("MENU\n");
        printf("1. CALL\n");
        printf("2. BACK\n");
        printf("3. REDIAL\n");
        printf("4. HISTORY\n");
        printf("5. EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                Call newCall;
                newCall.time = 0;
                printf("Enter number phone:");
                scanf("%s", &newCall.numberPhone);
                push(backStack, newCall);
                enqueue(historyCall, newCall);
                break;
            case 2:
                Call *backCall;
                backCall = pop(backStack);
                if(backCall == NULL) {
                    break;
                }
                push(forwardStack, *backCall);
                break;
            case 3:
                Call* forwardCall = pop(forwardStack);
                if(forwardCall == NULL) {
                    break;
                }
                push(backStack, *forwardCall);
                enqueue(historyCall, *forwardCall);
                break;
            case 4:
                printf("LICH SU CUOC GOI:\n");
                showHistoryCall(historyCall);
                break;
            case 5:
                printf("Thoat chuong trinh");
                break;
            default:
                printf("Invalid choice:");
        }
    }while (choice != 5);
    return 0;
}