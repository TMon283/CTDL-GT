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

void printList(Node* head) {
    int i = 1;
    Node* current = head;
    while (current != NULL) {
        printf("Node %d:%d\n",i++, current->data);
        current = current->next;
    }
}

void swap(Node** head) {
    if(*head == NULL || (*head)->next == NULL) {
        return;
    }
    Node* temp = NULL;
    Node* current = *head;
    *head = current->next;
    while (current != NULL && current->next != NULL) {
        Node* nextNode = current->next;
        Node* nextPair = nextNode->next;
        nextNode->next = current;
        current->next = nextPair;
        if (temp != NULL) {
            temp->next = nextNode;
        }
        temp = current;
        current = nextPair;
    }
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

    swap(&head);
    printList(head);
    return 0;
}