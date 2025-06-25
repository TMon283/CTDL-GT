#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int size);
int binarySearch(int arr[], int size, int target);

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
    printf("Enter element to be search:");
    scanf("%d", &target);
    bubbleSort(arr, size);
    int result = binarySearch(arr, size, target);
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

int binarySearch(int arr[], int size, int target) {
    int min = 0;
    int max = size - 1;
    while (min <= max) {
        int mid = (min + max) / 2;
        if (arr[mid] == target) {
            return arr[mid];
        } else if (arr[mid] < target) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return -1;
}