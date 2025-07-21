#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

int main() {
    int value;
    printf("Nhap gia tri data:");
    scanf("%d", &value);
    Node *root = createNode(value);
    root->left = NULL;
    root->right = NULL;
    printf("node = {\n"
           "\tdata: %d,\n"
           "\tleft->NULL,\n"
           "\tright->NULL\n"
           "}", root->data);
    free(root);
    return 0;
}