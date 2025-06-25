#include<stdio.h>
#include<stdlib.h>

int findIndexOfMax(int arr[], int size);

int main() {
    int size;
    printf("Enter the size of array:");
    scanf("%d", &size);
    if (size < 1) {
        printf("Invalid input");
        return 0;
    }
    int *arr = (int*)malloc(size*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 0;
    }
    for (int i = 0; i < size; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("Index of max: %d", findIndexOfMax(arr, size));
    free(arr);
    return 0;
}

int findIndexOfMax(int arr[], int size) {
    int max = arr[0];
    int result = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            result = i;
        }
    }
    return result;
}