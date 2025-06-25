#include<stdio.h>
#include<string.h>

struct Student {
    int id;
    char name[20];
    int age;
};

int main() {
    int size;
    printf("Enter the number of students:");
    scanf("%d", &size);
    struct Student arr[size];
    int id = 1;
    for (int i = 0; i < size; i++) {
        arr[i].id = id;
        id++;
        printf("Enter student name:");
        scanf("%s", arr[i].name);
        printf("Enter student age:");
        scanf("%d", &arr[i].age);
    }
    char keyword[10];
    printf("Enter the keyword:");
    scanf("%s", &keyword);
    for (int i = 0; i < size; i++) {
        if (strstr(strlwr(arr[i].name), strlwr(keyword)) == NULL) {
            continue;
        } else {
            printf("Student ID:%d\n", arr[i].id);
            printf("Student name:%s\n", arr[i].name);
            printf("Student age:%d\n", arr[i].age);
        }
    }
    return 0;
}