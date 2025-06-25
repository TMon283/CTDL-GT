#include<stdio.h>
#include<stdlib.h>

struct Student {
    int id;
    char name[20];
    int age;
};

int main() {
    int size, target;
    printf("Enter number of students:");
    scanf("%d", &size);
    if (size < 1) {
        printf("Invalid input");
        return 0;
    }
    struct Student arr[size];
    int id = 1;
    for (int i = 0; i < size; i++) {
        arr[i].id = id;
        id++;
        printf("Enter student name:");
        scanf("%s", &arr[i].name);
        printf("Enter student age:");
        scanf("%d", &arr[i].age);
    }
    printf("Enter student ID you want to found:");
    scanf("%d", &target);
    if (target < 1 || target > size) {
        printf("Not found");
    }
    for (int i = 0; i < size; i++) {
        if (arr[i].id == target) {
            printf("Student ID:%d\n", arr[i].id);
            printf("Student name:%s\n", arr[i].name);
            printf("Student age:%d\n", arr[i].age);
        }
    }
    return 0;
}