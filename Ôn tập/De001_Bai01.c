#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Task {
    int id;
    char title[100];
    int priority;
    char deadline[100];
}Task;

typedef struct SinglyNode {
    Task task;
    struct SinglyNode* next;
}SinglyNode;

typedef struct DoubleNode {
    Task task;
    struct DoubleNode* next;
    struct DoubleNode* prev;
}DoubleNode;

SinglyNode* createSingleNode(Task task) {
    SinglyNode* newNode = (SinglyNode*)malloc(sizeof(SinglyNode));
    newNode->task = task;
    newNode->next = NULL;
    return newNode;
}

DoubleNode* createDoubleNode(Task task) {
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->task = task;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

SinglyNode* insertSingleNodeAtEnd(SinglyNode* head, Task task) {
    SinglyNode* newNode = createSingleNode(task);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    SinglyNode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

DoubleNode* insertDoubleNodeAtEnd(DoubleNode* doubleHead, Task task) {
    DoubleNode* newNode = createDoubleNode(task);
    if (doubleHead == NULL) {
        doubleHead = newNode;
        return doubleHead;
    }
    DoubleNode* current = doubleHead;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return doubleHead;
}

void displayTaskList(SinglyNode* head) {
    SinglyNode* current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        printf("ID: %d\n", current->task.id);
        printf("Title: %s\n", current->task.title);
        printf("Priority: %d\n", current->task.priority);
        printf("Deadline: %s\n", current->task.deadline);
        current = current->next;
        printf("\n");
    }
}

SinglyNode* findSingleNodeToDone(SinglyNode* head, int id) {
    while (head != NULL) {
        if (head->task.id == id) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

void displayDone(DoubleNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    DoubleNode* current = head;
    while (current != NULL) {
        printf("ID: %d\n", current->task.id);
        printf("Title: %s\n", current->task.title);
        printf("Priority: %d\n", current->task.priority);
        printf("Deadline: %s\n", current->task.deadline);
        current = current->next;
    }
}

SinglyNode* deleteNodeByID(SinglyNode* head, int id) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    SinglyNode* current = head;
    SinglyNode* prev = NULL;
    while (current != NULL && current->task.id != id) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Can't found\n");
        return head;
    }
    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
    return head;
}


void updateTaskByID(SinglyNode* head, int id) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    SinglyNode* current = head;
    while (current != NULL && current->task.id != id) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Task not found\n");
        return;
    }
    printf("Old Title:%s\n", current->task.title);
    printf("Old Priority:%d\n", current->task.priority);
    printf("Old Deadline:%s\n", current->task.deadline);
    printf("\n");
    printf("New Tille:");
    scanf("%s", current->task.title);
    getchar();
    printf("New Priority:");
    scanf("%d", &current->task.priority);
    getchar();
    printf("New Deadline:");
    scanf("%s", current->task.deadline);
    getchar();
}

void sortTaskListByPriority(SinglyNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    for (SinglyNode* i = head; i != NULL; i = i->next) {
        for (SinglyNode* j = i->next; j != NULL; j = j->next) {
            if (i->task.priority > j->task.priority) {
                Task temp = j->task;
                j->task = i->task;
                i->task = temp;
            }
        }
    }
}

void searchTaskByTitle(SinglyNode* head, char *title) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    SinglyNode* current = head;
    int searched = -1;
    while (current != NULL) {
        if (strcmp(current->task.title, title) == 0) {
            searched = 0;
            printf("ID: %d\n", current->task.id);
            printf("Title: %s\n", current->task.title);
            printf("Priority: %d\n", current->task.priority);
            printf("Deadline: %s\n", current->task.deadline);
            printf("\n");
        }
        current = current->next;
    }
    if (searched == -1) {
        printf("Can't find...\n");
    }
}

int main() {
    int choice;
    int id = 1;
    SinglyNode* head = NULL;
    DoubleNode* doubleHead = NULL;
    Task task;
    do {
        printf("--------TASK MANAGER--------\n");
        printf("1. Add task\n");
        printf("2. Show task\n");
        printf("3. Delete task\n");
        printf("4. Update task\n");
        printf("5. Mark done task\n");
        printf("6. Sort task\n");
        printf("7. Search task\n");
        printf("8. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                task.id = id++;
                printf("Title:");
                scanf("%s", task.title);
                printf("Priority:");
                scanf("%d", &task.priority);
                getchar();
                printf("Deadline:");
                scanf("%s", task.deadline);
                getchar();
                head = insertSingleNodeAtEnd(head, task);
                break;
            case 2:
                printf("\nTASK LIST\n");
                displayTaskList(head);
                break;
            case 3:
                int deleteId;
                printf("Enter Task ID to delete:");
                scanf("%d", &deleteId);
                head = deleteNodeByID(head, deleteId);
                break;
            case 4:
                int updateId;
                printf("Enter Task ID to update:");
                scanf("%d", &updateId);
                updateTaskByID(head, updateId);
                break;
            case 5:
                int doneId;
                printf("Enter ID to done Task:");
                scanf("%d", &doneId);
                SinglyNode* doneNode = findSingleNodeToDone(head, doneId);
                if (doneNode == NULL) {
                    printf("Task not found\n");
                    break;
                }
                Task doneTask = doneNode->task;
                doubleHead = insertDoubleNodeAtEnd(doubleHead, doneTask);
                head = deleteNodeByID(head, doneId);
                printf("Task ID %d marked!\n", doneId);
                displayDone(doubleHead);
                break;
            case 6:
                sortTaskListByPriority(head);
                displayTaskList(head);
                break;
            case 7:
                char searchTitle[100];
                printf("Enter search title:");
                scanf("%s", searchTitle);
                searchTaskByTitle(head, searchTitle);
                break;
            case 8:
                printf("Exit...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 8);
    return 0;
}