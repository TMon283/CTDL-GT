#include<stdio.h>
#include<stdlib.h>

int findLastElement(int arr[], int size);

int main() {
    int size;
    printf("Enter size of array:");
    scanf("%d", &size);
    if (size < 1) {
        printf("Invalid input");
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
    int result = findLastElement(arr, size);
    if (result == -1) {
        printf("Element not found");
    } else {
        printf("%d", result);
    }
    free(arr);
    return 0;
}

int findLastElement(int arr[], int size) {
    int element;
    printf("Enter element to be search:");
    scanf("Element found at index = %d", &element);
    for (int i = size - 1; i >= 0; i--) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1;
}