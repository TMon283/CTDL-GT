#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error!\n");
        return NULL;
    }
    newNode->data = value;
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

Queue* createQueue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, Node* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = node;
    newNode->next = NULL;
    if (!q->rear) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

Node* dequeue(Queue* q) {
    if (!q->front) return NULL;
    QueueNode* temp = q->front;
    Node* result = temp->treeNode;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return result;
}

int isEmpty(Queue* q) {
    return q->front == NULL;
}

int exists(Node* root, int value) {
    if (!root) return 0;
    if (root->data == value) return 1;
    return exists(root->left, value) || exists(root->right, value);
}

void insertNodeToBinaryTree(Node* root, int value) {
    if (root == NULL) return;
    Queue* q = createQueue(100);
    enqueue(q, root);
    if (exists(root, value)) {
        printf("Gia tri %d da ton tai\n", value);
        return;
    }
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->left == NULL) {
            current->left = createNode(value);
            break;
        } else {
            enqueue(q, current->left);
        }
        if (current->right == NULL) {
            current->right = createNode(value);
            break;
        } else {
            enqueue(q, current->right);
        }
    }
    free(q);
}

int countLeaves(Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

int findLevel(Node* root, int value) {
    if (root == NULL) return -1;
    if (root->data == value) return 0;
    int leftLevel = findLevel(root->left, value);
    if (leftLevel >= 0) return leftLevel + 1;
    int rightLevel = findLevel(root->right, value);
    if (rightLevel >= 0) return rightLevel + 1;
    return -1;
}

Node* deleteTreeNode(Node* root, int data) {
    Queue* q = createQueue(100);
    enqueue(q, root);
    Node* target = NULL;
    Node* lastNode = NULL;
    Node* lastParent = NULL;
    while (!isEmpty(q)) {
        Node* current = dequeue(q);
        if (current->data == data) {
            target = current;
        }
        if (current->left != NULL) {
            enqueue(q, current->left);
            lastNode = current->left;
            lastParent = current;
        }
        if (current->right != NULL) {
            enqueue(q, current->right);
            lastNode = current->right;
            lastParent = current;
        }
    }
    target->data = lastNode->data;
    if (lastParent->left == lastNode) {
        lastParent->left = NULL;
    } else {
        lastParent->right = NULL;
    }
    free(lastNode);
    free(q);
}

int main() {
    int value;
    printf("Nhap root->data:");
    scanf("%d", &value);
    Node* root = createNode(value);
    for (int i = 0; i < 5; i++) {
        printf("Nhap node->data:");
        scanf("%d", &value);
        insertNodeToBinaryTree(root, value);
    }
    printf("Nhap gia tri can xoa: ");
    scanf("%d", &value

    );

}