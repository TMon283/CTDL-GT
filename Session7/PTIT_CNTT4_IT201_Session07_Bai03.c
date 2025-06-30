#include<stdio.h>
#include<stdlib.h>

void insertionSort(int arr[], int number);

int main() {
    int number;
    printf("Enter number of index:");
    scanf("%d", &number);
    if (number < 1 || number > 999) {
        printf("Invalid input");
        return 0;
    }
    int *arr = (int*)malloc(number*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 0;
    }
    for (int i = 0; i < number; i++) {
        printf("arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    printf("before:");
    for (int i = 0; i < number; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nafter:");
    insertionSort(arr, number);
    for (int i = 0; i < number; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

void insertionSort(int arr[], int number) {
    for (int i = 1; i < number; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}