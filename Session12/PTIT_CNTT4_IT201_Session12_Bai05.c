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

Node* deleteValue(Node* head, int value) {
    while (head && head->data == value) {
        Node* node = head;
        head = head->next;
        if (head != NULL) head->prev = NULL;
        free(node);
    }
    Node* current = head;
    while (current != NULL) {
        if(current->data == value) {
            Node* del = current;
            Node* left = current->prev;
            Node* right = current->next;

            if (left != NULL) left->next = right;
            if (right != NULL) right->prev = left;
            current = right;
            free(del);
        } else {
            current = current->next;
        }
    }
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
    Node* head =createNode(1);
    Node* node1 =createNode(2);
    Node* node2 =createNode(5);
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

    int n;
    printf("Enter value to remove:");
    scanf("%d", &n);
    head = deleteValue(head, n);
    printNode(head);
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    return 0;
}