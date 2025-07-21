#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* node) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->treeNode = node;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
}

Node* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    QueueNode* temp = q->front;
    Node* node = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}


Node* searchBFS(Node* root, int target) {
    if (root == NULL) return NULL;

    Queue* q = createQueue();
    enqueue(q, root);

    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->data == target) {
            return current;
        }
        if (current->left != NULL) enqueue(q, current->left);
        if (current->right != NULL) enqueue(q, current->right);
    }

    return NULL;
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
    Node *findNode = searchBFS(root, findData);
    if (findNode!=NULL) {
        printf("True");
    } else {
        printf("False");
    }
    free(arr);
    free(root);
    return 0;
}