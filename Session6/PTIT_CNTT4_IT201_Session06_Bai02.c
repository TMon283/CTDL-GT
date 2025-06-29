#include<stdio.h>
#include<stdlib.h>

int fibonacciNum(int number);

int main() {
    int number;
    printf("Enter number:");
    scanf("%d", &number);
    if (number <= 0) {
        printf("Invalid input");
        return 0;
    }
    int *arr = (int*)malloc(number*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return -1;
    }
    for (int i = 0; i < number; i++) {
        arr[number - 1 - i] = fibonacciNum(i);
    }
    for (int i = 0; i < number; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

int fibonacciNum(int number) {
    if (number == 0) return 0;
    if (number == 1) return 1;
    return fibonacciNum(number - 1) + fibonacciNum(number - 2);
}