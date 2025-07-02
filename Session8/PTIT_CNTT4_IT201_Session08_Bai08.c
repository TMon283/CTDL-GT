#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int n);
int binarySearch(int arr[], int n, int search);
int linearSearch(int arr[], int n, int search);

int main() {
    int n, search;
    printf("Enter size of array:");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("Invalid input");
        return 0;
    }
    int *arr =(int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    printf("before sorting:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    insertionSort(arr, n);
    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter element:");
    scanf("%d", &search);
    int result = binarySearch(arr, n, search);
    if (result == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index by binarySearch: %d", result);
    }
    printf("\n");
    int result2 = linearSearch(arr, n, search);
    if (result2 == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index by linearSearch: %d", result2);
    }
    free(arr);
    return 0;
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int binarySearch(int arr[], int n, int search) {
    int min = 0;
    int max = n - 1;
    while (min <= max) {
        int mid = (min + max) / 2;
        if (arr[mid] == search) {
            return mid;
        } else if (arr[mid] < search) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return -1;
}

int linearSearch(int arr[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            return i;
        }
    }
    return -1;
}