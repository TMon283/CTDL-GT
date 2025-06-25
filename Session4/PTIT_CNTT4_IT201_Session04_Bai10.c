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
    getchar();
    struct Student arr[size];
    int id = 1;
    for (int i = 0; i < size; i++) {
        arr[i].id = id;
        id++;
        printf("Enter student name:");
        fgets(arr[i].name, 20, stdin);
        printf("Enter student age:");
        scanf("%d", &arr[i].age);
        getchar();
        if (arr[i].age < 0) {
            printf("Invalid input");
            return 0;
        }
    }
    char keyword[10];
    printf("Enter the keyword:");
    scanf("%s", &keyword);
    for (int i = 0; i < size; i++) {
        if (strstr(strlwr(arr[i].name), strlwr(keyword)) == NULL) {
            continue;
        } else {
            printf(" id:%d\n name:%s age:%d\n\n", arr[i].id, arr[i].name, arr[i].age);
        }
    }
    return 0;
}