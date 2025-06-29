#include<stdio.h>

int findFactorial(int input);

int main() {
    int input;
    printf("Enter number:");
    scanf("%d", &input);
    getchar();
    if (input <= 0) {
        printf("Invalid input");
        return 0;
    }
    int result = findFactorial(input);
    printf("Output:%d", result);
    return 0;
}

int findFactorial(int input) {
    if (input == 1) return 1;
    return input * findFactorial(input - 1);
}