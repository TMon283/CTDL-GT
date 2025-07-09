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

void viewAll(Stacks stack) {
    printf("Output:\n");
    for(int i = stack.top; i >= 0; i--) {
        printf("%d\n", stack.data[i]);
    }
}

int main() {
    Stacks stack = createStack(5);
    for(int i = 0; i < 5; i++) {
        int data;
        printf("Enter element #%d:", i+1);
        scanf("%d", &data);
        push(&stack, data);
    }
    viewAll(stack);
    free(stack.data);
    return 0;
}