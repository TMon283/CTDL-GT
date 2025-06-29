#include<stdio.h>

int findSum(int input);

int main() {
    int input;
    printf("Enter the number:");
    scanf("%d", &input);
    getchar();
    if (input <= 0) {
        printf("Invalid input");
        return 0;
    }
    int result = findSum(input);
    printf("Output:%d", result);
    return 0;
}

int findSum(int input) {
    if (input == 0) return 0;
    return input + findSum(input - 1);
}