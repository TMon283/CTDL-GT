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

Node* searchDFS(Node* root, int target) {
    if (root == NULL) return NULL;
    if (root->data == target) return root;
    Node* leftResult = searchDFS(root->left, target);
    if (leftResult != NULL) return leftResult;
    return searchDFS(root->right, target);
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

    int findData;
    printf("Nhap data can tim:");
    scanf("%d", &findData);
    Node *findNode = searchDFS(root, findData);
    if (findNode!=NULL) {
        printf("True");
    } else {
        printf("False");
    }
    free(arr);
    free(root);
    return 0;
}