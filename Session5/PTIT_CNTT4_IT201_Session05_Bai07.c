#include<stdio.h>
#include<stdlib.h>

int printFibonacciNumber(int number);

int main() {
    int number;
    printf("Enter a number of fibonacci numbers:");
    scanf("%d", &number);
    if (number == 0) {
        printf("Invalid input");
        return 0;
    }
    int *arr = (int*)malloc(number*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 0;
    }
    for (int i = 0; i < number; i++) {
        arr[i] = printFibonacciNumber(i);
    }
    for (int i = 0; i < number; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

int printFibonacciNumber(int number) {
    if (number == 0) return 0;
    if (number == 1) return 1;
    return printFibonacciNumber(number - 1) + printFibonacciNumber(number - 2);
}