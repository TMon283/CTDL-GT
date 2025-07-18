#include<stdio.h>
#include<stdlib.h>

typedef struct history {
    char url[20];
    char timeStamp[20];
}history;



int main() {
    int choice;
    do {
        printf("WEB HISTORY\n");
        printf("1. VISIT URL\n");
        printf("2. BACKWARD\n");
        printf("3. FORWARD\n");
        printf("4. CURRENR\n");
        printf("5. EXIT\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                printf("Exit...\n");
                break;
            default:
                printf("Invalid Choice\n");
        }
    } while (choice != 5);
    return 0;
}