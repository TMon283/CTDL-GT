#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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

int isEmpty(const Stacks stack) {
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
    if (isEmpty(*stack)) {
        printf("No element in stack\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int evaluatePostfix(char expr[]) {
    Stacks s = createStack(10);
    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];
        if (c >= '0' && c <= '9') {
            push(&s, c - '0');
        } else {
            int b = pop(&s);
            int a = pop(&s);
            int result;
            switch (c) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Error: Division by zero\n");
                        return 0;
                    }
                    result = a / b;
                    break;
                default:
                    printf("Unknown operator: %c\n", c);
                    return 0;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}


int main(void) {
    char expr[101];
    printf("Enter input:");
    fgets(expr, sizeof(expr), stdin);
    int len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n') {
        expr[len - 1] = '\0';
    }
    int result = evaluatePostfix(expr);
    printf("Result: %d\n", result);
    return 0;
}