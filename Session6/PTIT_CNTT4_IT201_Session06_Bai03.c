#include<stdio.h>

int sum(int number);

int main() {
    int number;
    printf("Enter number:");
    scanf("%d", &number);
    if (number <= 0) {
        printf("Invalid input");
        return 0;
    }
    int result = sum(number);
    printf("Output:%d", result);
    return 0;
}

int sum(int number) {
    if (number == 0) return 0;
    return (number % 10) + sum(number / 10);
}