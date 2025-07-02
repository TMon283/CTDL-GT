#include<stdio.h>
#include<stdlib.h>

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
    printf("Enter element:");
    scanf("%d", &search);
    int result = linearSearch(arr, n, search);
    if (result == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index: %d", result);
    }
    free(arr);
    return 0;
}

int linearSearch(int arr[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            return i + 1;
        }
    }
    return -1;
}