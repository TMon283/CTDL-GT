#include<stdio.h>
#include<stdlib.h>

void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

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
    quickSort(arr, 0, number - 1);
    for (int i = 0; i < number; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}