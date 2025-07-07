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

Node* sortNode(Node* head) {
    Node* sorted = NULL;
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->next;
        current->prev = current->next = NULL;
        if (!sorted) {
            sorted = current;
        }
        else if (current->data < sorted->data) {
            current->next = sorted;
            sorted->prev = current;
            sorted = current;
        }
        else {
            Node* p = sorted;
            while (p->next && p->next->data < current->data) {
                p = p->next;
            }
            current->next = p->next;
            if (p->next) p->next->prev = current;
            p->next = current;
            current->prev = p;
        }
        current = nextNode;
    }
    return sorted;
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
    Node* head =createNode(6);
    Node* node1 =createNode(2);
    Node* node2 =createNode(5);
    Node* node3 =createNode(4);
    Node* node4 =createNode(1);
    Node* node5 =createNode(8);

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

    head = sortNode(head);
    printNode(head);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}