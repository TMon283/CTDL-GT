#include<stdio.h>
#include<stdlib.h>

void selectionSort(int arr[], int number);

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
    selectionSort(arr, number);
    for (int i = 0; i < number; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

void selectionSort(int arr[], int number) {
    for (int i = 0; i < number - 1; i++) {
        int min = i;
        for (int j = i + 1; j < number; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}