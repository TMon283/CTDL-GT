#include<stdio.h>
#include<stdlib.h>

int findMax(int arr[], int size);
int findMin(int arr[], int size);

int main() {
    int size;
    printf("Enter size of array:");
    scanf("%d", &size);
    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return -1;
    }
    for (int i = 0; i < size; i++) {
        printf("arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    int max = findMax(arr, size - 1);
    int min = findMin(arr, size - 1);
    printf("Output: %d, %d", max, min);
    free(arr);
    return 0;
}

int findMax(int arr[], int size) {
    if (size == 1) return arr[0];
    int max = findMax(arr, size - 1);
    if (max < arr[size - 1]) {
        return arr[size - 1];
    } else {
        return max;
    }
}

int findMin(int arr[], int size) {
    if (size == 1) return arr[0];
    int min = findMin(arr, size - 1);
    if (min > arr[size - 1]) {
        return arr[size - 1];
    } else {
        return min;
    }
}