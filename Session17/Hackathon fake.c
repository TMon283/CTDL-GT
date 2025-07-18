#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Course {
    int id;
    char title[100];
    int credit;
} Course;

typedef struct SingleNode {
    Course course;
    struct SingleNode *next;
} SingleNode;

typedef struct DoubleNode {
    Course course;
    struct DoubleNode *next;
    struct DoubleNode *prev;
} DoubleNode;

SingleNode* createSingleNode(Course course) {
    SingleNode* newNode = (SingleNode*)malloc(sizeof(SingleNode));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho cho node\n");
        exit(1);
    }
    newNode->course = course;
    newNode->next = NULL;
    return newNode;
}


SingleNode* insertSingleNodeAtEnd(SingleNode *head, Course course) {
    SingleNode* newNode = createSingleNode(course);
    if (head == NULL) {
        head = newNode;
        return head;
    }
    SingleNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

SingleNode* deleteSingleNodeAt(SingleNode *head, int id) {
    if (head == NULL) {
        printf("Danh sach trong\n");
        return head;
    }
    SingleNode *temp = head;
    SingleNode *prev = NULL;
    while (temp != NULL && temp->course.id != id) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay course co id la %d", id);
        return head;
    }
    if (temp == head) {
        head = head->next;
        free(temp);
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

void updateCourseById(SingleNode *head, int id) {
    if (head == NULL) {
        printf("Danh sach trong\n");
        return;
    }
    SingleNode *temp = head;
    while (temp != NULL && temp->course.id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay course co id la %d", id);
        return;
    }
    if (temp == head) {
        head = head->next;
        free(temp);
        return;
    }
    printf("Course ID: %d\n", temp -> course.id);
    printf("Old title: %s\n", temp -> course.title);
    printf("Old credit: %d\n", temp -> course.credit);
    printf("Nhap vao title moi:");
    scanf("%s", temp -> course.title);
    printf("Nhap vao credit moi:");
    scanf("%d", &temp -> course.credit);
}

void displaySingleList(SingleNode *head) {
    SingleNode* temp = head;
    if (head == NULL) {
        printf("Danh sach trong");
        return;
    }
    while (temp != NULL) {
        printf("Course ID: %d\n", temp->course.id);
        printf("Title: %s\n", temp->course.title);
        printf("Credit: %d\n", temp->course.credit);
        temp = temp->next;
        printf("\n");
    }
}

void markCourseCompleted(SingleNode* head, int id) {
    SingleNode* temp = head;
    while (temp != NULL && temp->course.id != id) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Khong tim thay course co id la %d\n", id);
        return;
    }
    strcat(temp->course.title, "_[DA HOAN THANH]");
    printf("Da danh dau khoa hoc da hoan thanh.\n");
}

void sortCoursesByCredit(SingleNode* head) {
    if (head == NULL) return;
    int swapped;
    SingleNode* ptr1;
    SingleNode* lptr = NULL;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->course.credit > ptr1->next->course.credit) {
                Course temp = ptr1->course;
                ptr1->course = ptr1->next->course;
                ptr1->next->course = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
    printf("Da sap xep khoa hoc theo so tin chi\n");
}

void searchCourseByTitle(SingleNode* head, char* title) {
    SingleNode* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->course.title, title) == 0) {
            printf("Tim thay:\n");
            printf("Course ID: %d\n", temp->course.id);
            printf("Title: %s\n", temp->course.title);
            printf("Credit: %d\n\n", temp->course.credit);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) printf("Khong tim thay khoa hoc co title la %s\n", title);
}

int main() {
    int choice;
    int id = 1;
    SingleNode* singleHead = NULL;
    DoubleNode* doubleHead = NULL;
    do {
        printf("\nMENU");
        printf("\n1. Them khoa hoc");
        printf("\n2. Hien thi danh sach khoa hoc");
        printf("\n3. Xoa khoa hoc");
        printf("\n4. Cap nhat thong tin khoa hoc");
        printf("\n5. Danh dau khoa hoc da hoan thanh");
        printf("\n6. Sap xep khoa hoc theo so tin chi");
        printf("\n7. Tim kiem khoa hoc theo ten");
        printf("\n8. Thoat chuong trinh");
        printf("\nLua chon cua ban:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                Course newCourse;
                newCourse.id = id++;
                printf("Nhap title:");
                scanf("%s", newCourse.title);
                printf("Nhap credit:");
                scanf("%d", &newCourse.credit);
                singleHead = insertSingleNodeAtEnd(singleHead, newCourse);
                break;
            case 2:
                printf("DANH SACH KHOA HOC\n");
                displaySingleList(singleHead);
                break;
            case 3:
                int deleteId;
                printf("Nhap course id:");
                scanf("%d", &deleteId);
                singleHead = deleteSingleNodeAt(singleHead, deleteId);
                break;
            case 4:
                int updateId;
                printf("Nhap course id:");
                scanf("%d", &updateId);
                updateCourseById(singleHead, updateId);
                break;
            case 5: {
                int completeId;
                printf("Nhap course id:");
                scanf("%d", &completeId);
                markCourseCompleted(singleHead, completeId);
                break;
            }
            case 6:
                sortCoursesByCredit(singleHead);
                break;
            case 7: {
                char titleSearch[100];
                printf("Nhap title khoa hoc can tim:");
                scanf("%s", titleSearch);
                searchCourseByTitle(singleHead, titleSearch);
                break;
            }
            case 8:
                printf("Thoat chuong trinh. Tam biet!");
                break;
            default:
                printf("Lua chon khong hop le");
        }
    } while (choice != 8);
    return 0;
}