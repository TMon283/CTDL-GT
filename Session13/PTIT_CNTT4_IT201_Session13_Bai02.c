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

void printStack(Stacks *stack) {
    printf("stack={\n");
    printf("element: [");
    for(int i = 0; i <= stack->top; i++) {
        if(i != stack->top) {
            printf("%d, ", stack->data[i]);
        } else {
            printf("%d", stack->data[i]);
        }
    }
    printf("]\n");
    printf("top:%d, \n", stack->top);
    printf("cap:%d\n", stack->max);
    printf("}\n");
}

int main() {
    Stacks stack = createStack(5);
    printf("Enter 5 elements\n");
    for(int i = 0; i < 5; i++) {
        int data;
        printf("Enter element #%d:", i+1);
        scanf("%d", &data);
        push(&stack, data);
    }
    printStack(&stack);
    free(stack.data);
    return 0;
}