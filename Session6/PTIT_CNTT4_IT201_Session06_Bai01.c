#include<stdio.h>

void binaryNumber(int number);

int main() {
    int number;
    printf("Enter number:");
    scanf("%d", &number);
    if (number < 0) {
        printf("Invalid input");
        return 0;
    }
    binaryNumber(number);
    return 0;
}

void binaryNumber(int number) {
    if (number == 0) return;
    binaryNumber(number / 2);
    printf("%d", number % 2);
}