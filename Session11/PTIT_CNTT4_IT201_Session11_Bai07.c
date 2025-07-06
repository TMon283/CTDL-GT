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

Node* insertNodeAtHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

Node* insertNodeAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

Node* insertNodeAtPosition(Node* head, int data, int position) {
    if (position < 1 || position > getLength(head)) {
        printf("Index is out of range\n");
        return head;
    }
    if (position == 1) {
        return insertNodeAtHead(head, data);
    }
    if (position == getLength(head)) {
        return insertNodeAtEnd(head, data);
    }
    Node* current = head;
    for (int i = 1; i < position; i++) {
        current = current->next;
    }
    Node* newNode = createNode(data);
    Node* prev = current->prev;
    newNode->next = current;
    current->prev = newNode;
    prev->next = newNode;
    newNode->prev = prev;
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

    int value, position;
    printf("Enter value:");
    scanf("%d", &value);
    printf("Enter position:");
    scanf("%d", &position);
    head = insertNodeAtPosition(head, value, position);
    printNode(head);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}
