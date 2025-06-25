#include<stdio.h>
#include<stdlib.h>

int findIndexOfMin(int arr[], int size);

int main() {
    int size;
    printf("Enter the size of array:");
    scanf("%d", &size);
    if (size < 1) {
        printf("Invalid input");
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
    printf("Index of min: %d", findIndexOfMin(arr, size));
    free(arr);
    return 0;
}

int findIndexOfMin(int arr[], int size) {
    int min = arr[0];
    int result = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            result = i;
        }
    }
    return result;
}