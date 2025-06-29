#include<stdio.h>
#include<stdlib.h>

int printArray(int arr[], int size, int i);

int main() {
    int size;
    int index = 0;
    printf("Enter size of array:");
    scanf("%d", &size);
    getchar();
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
        getchar();
    }
    printArray(arr, size, index);
    free(arr);
    return 0;
}

int printArray(int arr[], int size, int index) {
    if (index == size) return 0;
    printf("%d ", arr[index]);
    return printArray(arr, size, index+1);
}