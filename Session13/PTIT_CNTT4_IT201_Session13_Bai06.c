#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char *data;
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

int isPalindrome(char *input) {
    int n = strlen(input);
    Stacks stack = createStack(n);
    for(int i = 0; i < n; i++) {
        push(&stack, input[i]);
    }
    for(int i = 0; i < n / 2; i++) {
        char c = pop(&stack);
        if(c != input[i]) {
            free(stack.data);
            return 0;
        }
    }
    free(stack.data);
    return 1;
}

int main() {
    char input[100];
    printf("Enter string:");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    if(isPalindrome(input)) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}