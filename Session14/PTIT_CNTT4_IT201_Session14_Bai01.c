#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
}stack;

void initStack(stack* s) {
    s->top = NULL;
}

int isEmpty(stack* s) {
    return s->top == NULL;
}

void push(stack *s,int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Empty Stack\n");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

int main(void) {
    stack s;
    initStack(&s);
    return 0;
}