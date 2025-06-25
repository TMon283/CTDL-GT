#include<stdio.h>
#include<stdlib.h>

int findFirstElement(int arr[], int size);

int main() {
    int size;
    printf("Enter size of array:");
    scanf("%d",&size);
    if (size < 1) {
        printf("Invalid input");
        return 0;
    }
    int *arr = (int*)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    int result = findFirstElement(arr, size);
    if (result == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index %d", result);
    }
    free(arr);
    return 0;
}

int findFirstElement(int arr[], int size) {
    int result;
    printf("Enter element to find:");
    scanf("%d", &result);
    for (int i = 0; i < size; i++) {
        if (arr[i] == result) {
            printf("Element found at index %d", i);
            return i;
        }
    }
    return -1;
}