#include<stdio.h>
#include<stdlib.h>

int sumOfArray(int arr[], int size);

int main() {
    int size;
    printf("Enter size of array:");
    scanf("%d", &size);
    if (size < 1) {
        printf("Invalid input");
        return 0;
    }
    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 0;
    }
    for (int i = 0; i < size; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    int sum = sumOfArray(arr, size);
    printf("Output:%d", sum);
    free(arr);
    return 0;
}

int sumOfArray(int arr[], int size) {
    if (size == 0) return 0;
    return arr[size - 1] + sumOfArray(arr, size - 1);
}