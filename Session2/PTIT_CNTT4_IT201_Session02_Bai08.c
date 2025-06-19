#include<stdio.h>
#include<stdlib.h>

void findGreater(int arr[], int size);

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    if (size < 0) {
        printf("Invalid input");
        return 1;
    }
    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    findGreater(arr, size);
    free(arr);
    return 0;
}

void findGreater(int arr[], int size) {
    int *result = (int*)malloc(size*sizeof(int));
    int count = 0;
    int maxRight = arr[size - 1];
    result[count++] = maxRight;
    for (int i = size - 2; i >= 0; i--) {
        if (arr[i] > maxRight) {
            maxRight = arr[i];
            result[count++] = maxRight;
        }
    }
    for (int i = count - 1; i >= 0; i--) {
        if (i == 0) {
            printf("%d", result[i]);
        } else {
            printf("%d, ", result[i]);
        }
    }
    free(result);
}