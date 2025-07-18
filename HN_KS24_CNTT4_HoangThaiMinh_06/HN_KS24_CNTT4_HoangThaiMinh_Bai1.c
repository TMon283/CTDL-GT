#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Project {
    int id;
    char title[100];
    char owner[100];
    int priority;
}Project;

typedef struct SinglyNode {
    Project project;
    struct SinglyNode *next;
}SinglyNode;

typedef struct DoubleNode {
    Project project;
    struct DoubleNode *next;
    struct DoubleNode *prev;
}DoubleNode;

SinglyNode* createSinglyNode(Project project) {
    SinglyNode *newNode = (SinglyNode *)malloc(sizeof(SinglyNode));
    newNode->project = project;
    newNode->next = NULL;
    return newNode;
}

SinglyNode* insertNodeAtEnd(SinglyNode* head, Project project) {
    SinglyNode *newNode = createSinglyNode(project);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    SinglyNode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void displayProjectList(SinglyNode* head) {
    SinglyNode *current = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (current != NULL) {
        printf("Project ID: %d\n",current->project.id);
        printf("Title: %s\n", current->project.title);
        printf("Owner: %s\n", current->project.owner);
        printf("Priority: %d\n", current->project.priority);
        printf("\n");
        current = current->next;
    }
}

SinglyNode* deleteNodeByID(SinglyNode* head, int id) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    SinglyNode *current = head;
    SinglyNode* prev = NULL;
    while (current != NULL && current->project.id != id) {
        prev = current;
        current = current->next;
    }
    if (current == head) {
        head = head->next;
        free(current);
        return head;
    }
    prev->next = current->next;
    free(current);
    return head;
}

void updateProjectByID(SinglyNode* head, int id) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    SinglyNode *current = head;
    while (current != NULL && current->project.id != id) {
        current = current->next;
    }
    if (current == head) {
        head = head->next;
        free(current);
        return;
    }
    printf("Old title:%s\n", current->project.title);
    printf("Old owner:%s\n", current->project.owner);
    printf("Old priority:%d", current->project.priority);
    printf("\n");
    printf("New title:");
    scanf("%s", current->project.title);
    printf("New owner:");
    scanf("%s", current->project.owner);
    printf("New Priority:");
    scanf("%d", &current->project.priority);
}

void sortByPriority(SinglyNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int swapped;
    SinglyNode* ptr1;
    SinglyNode* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->project.priority > ptr1->next->project.priority) {
                Project temp = ptr1->project;
                ptr1->project = ptr1->next->project;
                ptr1->next->project = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void searchProjectByTitle(SinglyNode* head, char* name) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    SinglyNode *current = head;
    int searched = 0;
    while (current != NULL) {
        if (strcmp(current->project.title, name) == 0) {
            printf("Title: %s\n", current->project.title);
            printf("Owner: %s\n", current->project.owner);
            printf("Priority: %d\n", current->project.priority);
            printf("\n");
        }
        current = current->next;
        searched++;
    }
    if (searched == 0) {
        printf("Can't find this project\n");
    }
}

int main() {
    int choice;
    int id = 1;
    SinglyNode *head = NULL;
    do {
        printf("MENU\n");
        printf("1. Add Project\n");
        printf("2. Display Project\n");
        printf("3. Delete Project\n");
        printf("4. Update Project\n");
        printf("5. Mark Project\n");
        printf("6. Sort By Priority\n");
        printf("7. Search Project\n");
        printf("8. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Project project;
                project.id = id++;
                printf("Project title:");
                scanf("%s", project.title);
                printf("Project owner:");
                scanf("%s", project.owner);
                printf("Project priority:");
                scanf("%d", &project.priority);
                head = insertNodeAtEnd(head, project);
                break;
            case 2:
                printf("PROJECT LIST\n");
                displayProjectList(head);
                break;
            case 3:
                int deleteId;
                printf("Enter Project ID to delete:");
                scanf("%d", &deleteId);
                head = deleteNodeByID(head, deleteId);
                break;
            case 4:
                int updateId;
                printf("Enter Project ID to update:");
                scanf("%d", &updateId);
                updateProjectByID(head, updateId);
                break;
            case 5:
                break;
            case 6:
                sortByPriority(head);
                displayProjectList(head);
                break;
            case 7:
                char name[20];
                printf("Enter Project Title to search:");
                scanf("%s", name);
                searchProjectByTitle(head, name);
                break;
            case 8:
                printf("Exit...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    }while (choice != 8);
    return 0;
}