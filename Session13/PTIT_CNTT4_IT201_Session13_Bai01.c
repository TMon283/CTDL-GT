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

int main() {
    Stacks stack = createStack(5);
    free(stack.data);
    return 0;
}