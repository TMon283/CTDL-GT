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

void preorder(Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    int arr[5];
    for (int i = 0; i < 5; i++) {
        printf("Nhap gia tri node %d:", i);
        scanf("%d", &arr[i]);
    }
    Node *root = createNode(arr[0]);
    Node *one = createNode(arr[1]);
    Node *two = createNode(arr[2]);
    Node *three = createNode(arr[3]);
    Node *four = createNode(arr[4]);

    root->left=one;
    root->right=two;
    root->left->left=three;
    root->left->right=four;
    preorder(root);
    free(arr);
    free(root);
    return 0;
}