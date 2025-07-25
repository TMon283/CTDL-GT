#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Copy {
    char data[100];
    struct Node* next;
}Copy;

typedef struct Stack {
    Copy* head;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isStackFull(Stack* stack) {
    if(stack->top == stack->capacity - 1) {
        return 1;
    }
    return 0;
}

int isStackEmpty(Stack* stack) {
    if(stack->top == -1) {
        return 1;
    }
    return 0;
}

void push(Stack* stack, Copy copy) {
    if (isStackFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    Copy* newNode = (Copy*)malloc(sizeof(Copy));
    strcpy(newNode->data, copy.data);
    newNode->next = stack->head;
    stack->head = newNode;
    stack->top++;
}

Copy pop(Stack* stack) {
    Copy empty = {"", NULL};
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return empty;
    }
    Copy* temp = stack->head;
    stack->head = stack->head->next;
    stack->top--;
    Copy result;
    strcpy(result.data, temp->data);
    free(temp);
    return result;
}

void clearStack(Stack* stack) {
    while (!isStackEmpty(stack)) {
        pop(stack);
    }
}

void showStack(Stack* stack) {
    if (isStackEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    Copy* current = stack->head;
    while (current->next != NULL) {
        printf("%s\n", current->data);
        current = current->next;
    }
}

int main() {
    int choice;
    Stack* clipboardStack = createStack(10);
    Stack* redoStack = createStack(10);
    do {
        printf("CLIPBOARD MANAGER\n");
        printf("1. COPY\n");
        printf("2. UNDO\n");
        printf("3. REDO\n");
        printf("4. SHOW\n");
        printf("5. EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Copy copy;
                printf("Enter copy data: ");
                scanf("%s", copy.data);
                push(clipboardStack, copy);
                clearStack(redoStack);
                break;
            }
            case 2: {
                Copy undo = pop(clipboardStack);
                if (strcmp(undo.data, "") != 0) {
                    push(redoStack, undo);
                    printf("Undo: %s\n", undo.data);
                }
                break;
            }
            case 3: {
                Copy redo = pop(redoStack);
                if (strcmp(redo.data, "") != 0) {
                    push(clipboardStack, redo);
                    printf("Redo: %s\n", redo.data);
                }
                break;
            }
            case 4: {
                printf("Clipboard History:\n");
                showStack(clipboardStack);
                break;
            }
            case 5:
                printf("Exit...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}