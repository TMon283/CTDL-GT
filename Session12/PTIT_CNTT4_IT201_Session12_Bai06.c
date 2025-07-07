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

Node* findMiddle(Node* head) {
    Node* start = head;
    Node* end = head;
    while (end != NULL && end->next != NULL) {
        start = start->next;
        end = end->next->next;
    }
    return start;
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
    Node* head =createNode(1);
    Node* node1 =createNode(2);
    Node* node2 =createNode(3);
    Node* node3 =createNode(4);
    Node* node4 =createNode(5);
    Node* node5 =createNode(6);

    head->next = node1;
    node1->prev = head;

    node1->next = node2;
    node2->prev = node1;

    node2->next = node3;
    node3->prev = node2;

    node3->next = node4;
    node4->prev = node3;

    node4->next = node5;
    node5->prev = node4;

    Node* mid = findMiddle(head);
    printf("Middle node:%d", mid->data);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}