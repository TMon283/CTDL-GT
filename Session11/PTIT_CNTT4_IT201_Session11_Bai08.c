#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

Node* deleteNodeAtHead(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* current = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(current);
    return head;
}

Node* deleteNodeAtEnd(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}

Node* deleteNodeAtPosition(Node* head, int position) {
    if (position < 1 || position > getLength(head)) {
        printf("Position out of bounds\n");
        return NULL;
    }
    if (position == 1) {
        return deleteNodeAtHead(head);
    }
    if (position == getLength(head)) {
        return deleteNodeAtEnd(head);
    }
    Node* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    Node* prev = current->prev;
    Node* next = current->next;
    Node* temp = current;
    prev->next = next;
    next->prev = prev;
    free(temp);
    return head;
}

void printNode(Node* head) {
    Node *current = head;
    while (current != NULL) {
        if (current->next == NULL) {
            printf(" %d -> ", current->data);
            printf("NULL\n");
        } else {
            printf(" %d <->", current->data);
        }
        current = current->next;
    }
}

int main() {
    Node* head =createNode(1);
    Node* node1 =createNode(2);
    Node* node2 =createNode(3);
    Node* node3 =createNode(4);
    Node* node4 =createNode(5);

    head->next = node1;
    node1->prev = head;

    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    int position;
    printf("Enter the position:");
    scanf("%d", &position);
    head = deleteNodeAtPosition(head, position);
    printNode(head);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}