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

Node* deleteHead(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* deleteEnd(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    Node* removeNode = current->next;
    current->next = NULL;
    free(removeNode);
    return head;
}

Node* deleteAt(Node* head, int index) {
    if (index > getLength(head) || index < 0) {
        printf("Index is out of range");
        return head;
    }
    if (index == 0) {
        return deleteHead(head);
    }
    if (index == getLength(head) - 1) {
        return deleteEnd(head);
    }
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* deleteNode = current->next;
    Node* next = deleteNode->next;
    current->next = next;
    free(deleteNode);
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

    int index;
    printf("Please enter index to delete:");
    scanf("%d",&index);
    deleteAt(head, index);
    printList(head);
    return 0;
}