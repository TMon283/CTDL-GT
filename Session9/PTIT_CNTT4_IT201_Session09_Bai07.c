#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

int getLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

Node* insertHead(Node* head, int value) {
    Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    return head;
}

Node* insertEnd(Node* head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) return newNode;
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    newNode->next = current;
    return head;
}

void printList(Node* head) {
    int i = 1;
    Node* current = head;
    while (current != NULL) {
        printf("Node %d:%d\n",i++, current->data);
        current = current->next;
    }
}


Node* insertAt(Node* head, int value, int position) {
    if (position > getLength(head) || position < 0) {
        printf("Invalid position");
        return head;
    }
    if (position == 0) {
        return insertHead(head, value);
    }
    if (position == getLength(head) - 1) {
        return insertEnd(head, value);
    }
    Node* current = head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    Node* newNode = createNode(value);
    newNode->next = current->next;
    current->next = newNode;
    printList(head);
    return head;
}

int main() {
    Node* head = createNode(1);
    Node* node1 = createNode(2);
    Node* node2 = createNode(3);
    Node* node3 = createNode(4);
    Node* node4 = createNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    int value, position;
    printf("Enter value to be inserted:");
    scanf("%d", &value);
    printf("Enter position to be inserted:");
    scanf("%d", &position);
    head = insertAt(head, value, position);
    return 0;
}