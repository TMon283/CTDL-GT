#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int *data;
    int top;
    int max;
}Stacks;

Stacks createStack(int max) {
    Stacks stack;
    stack.data = malloc(max * sizeof(int));
    stack.top = -1;
    stack.max = max;
    return stack;
}

int isFull(const Stacks stack) {
    return stack.top == stack.max - 1;
}

void push(Stacks *stack, int data) {
    if(isFull(*stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = data;
}

int pop(Stacks *stack) {
    if (stack->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int* reverse(int arr[], int n) {
    Stacks stack = createStack(n);
    for(int i = 0; i < n; i++) {
        push(&stack, arr[i]);
    }
    int *b = (int*)malloc(stack.max * sizeof(int));
    for(int i = 0; i < n; i++) {
        b[i] = pop(&stack);
    }
    free(stack.data);
    return b;
}

int main() {
    int n;
    printf("Enter number of elements:");
    scanf("%d", &n);
    Stacks stack = createStack(n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        int data;
        printf("arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    int *reverseArr = reverse(arr, n);
    printf("[");
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d, ", reverseArr[i]);
        } else {
            printf("%d", reverseArr[i]);
        }
    }
    printf("]\n");
    free(arr);
    free(reverseArr);
    free(stack.data);
    return 0;
}