#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

int isEmpty(Stacks stack) {
    return stack.top == -1;
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
    if(isEmpty(*stack)) {
        printf("Stack is empty\n");
        return 0;
    }
    return stack->data[stack->top--];
}

int isValidParentheses(char *input) {
    int n = strlen(input);
    Stacks stack = createStack(n);
    for(int i = 0; i < n; i++) {
        char c = input[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c);
        } else if (c == ')' || c == '}' || c == ']') {
            char top = pop(&stack);
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                free(stack.data);
                return 0;
            }
        }
    }
    int valid = isEmpty(stack);
    free(stack.data);
    return valid;
}


int main() {
    char input[1024];
    printf("Input:");
    fgets(input, 1024, stdin);
    input[strcspn(input, "\n")] = '\0';
    if (isValidParentheses(input)) {
        printf("True");
    } else {
        printf("False");
    }
    return 0;
}