#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node* appendNode(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printNode(Node* head) {
    Node* current = head;
    while (current != NULL) {
        if (current->next == NULL) {
            printf("%d -> ", current->data);
        } else {
            printf("%d <-> ", current->data);
        }
        current = current->next;
    }
    printf("NULL");
}

int main() {
    int n;
    printf("Enter number of nodes:");
    scanf("%d", &n);
    if (n < 0) {
        printf("Invalid Input");
    }
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter number:");
        scanf("%d", &data);
        head = appendNode(head, data);
    }
    printNode(head);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}