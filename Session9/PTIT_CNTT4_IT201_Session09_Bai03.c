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

int checkData(Node* head, int n) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == n) {
            return 1;
        }
        current = current->next;
    }
    return 0;
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
    int n;
    printf("Nhap n:");
    scanf("%d", &n);
    int flag = checkData(head, n);
    if (flag == 1) {
        printf("True");
    } else {
        printf("False");
    }
    return 0;
}