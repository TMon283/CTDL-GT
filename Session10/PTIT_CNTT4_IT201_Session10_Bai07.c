#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void sortNode(Node* head) {
    if (!head) return;
    Node *current, *nextNode;
    for (current = head; current->next; current = current->next) {
        for (nextNode = head; nextNode->next; nextNode = nextNode->next) {
            if (nextNode->data > nextNode->next->data) {
                int temp = nextNode->data;
                nextNode->data = nextNode->next->data;
                nextNode->next->data = temp;
            }
        }
    }
}

void printNode(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL");
}

int main() {
    Node* head = createNode(3);
    Node* node1 = createNode(2);
    Node* node2 = createNode(5);
    Node* node3 = createNode(1);
    Node* node4 = createNode(4);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    printf("before:");
    printNode(head);
    sortNode(head);
    printf("\n");
    printf("after:");
    printNode(head);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}