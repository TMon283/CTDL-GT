#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int number);

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
    bubbleSort(arr, number);
    for (int i = 0; i < number; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

void bubbleSort(int arr[], int number) {
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}