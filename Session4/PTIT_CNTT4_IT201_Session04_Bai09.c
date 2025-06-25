#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int size);
int binarySearch(int arr[], int target, int min, int max);

int main() {
    int size, target;
    printf("Enter size of array:");
    scanf("%d", &size);
    if (size < 1) {
        printf("Invalid input");
        return 0;
    }
    int *arr = (int*)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter element you want to search:");
    scanf("%d", &target);
    int min = 0;
    int max = size - 1;
    int result = binarySearch(arr, target, min, max);
    if (result == -1) {
        printf("Element not found");
    } else {
        printf("Element found");
    }
    free(arr);
    return 0;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int target, int min, int max) {
    while (min <= max) {
        int mid = (min + max) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] > target) {
            return binarySearch(arr, target, min, mid - 1);
        } else {
            return binarySearch(arr, target, mid + 1, max);
        }
    }
    return -1;
}