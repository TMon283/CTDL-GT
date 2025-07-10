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
        printf("Rong");
        return -1;
    }
    Node* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

void printStack(stack *s) {
    if (isEmpty(s)) {
        printf("Empty\n");
        return;
    }
    Node* temp = s->top;
    printf("stack ={\n");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n}\n");
}

int peek(stack *s) {
    if (isEmpty(s)) {
        printf("Empty\n");
        return -1;
    }
    return s->top->data;
}

int main(void) {
    stack s;
    initStack(&s);
    int n;
    printf("Enter number of input:");
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        int value;
        printf("Value:");
        scanf("%d",&value);
        push(&s,value);
    }
    printStack(&s);
    int result = peek(&s);
    if (result != -1) {
        printf("Value:%d", result);
    }
    return 0;
}