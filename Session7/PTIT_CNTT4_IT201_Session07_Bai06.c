#include<stdio.h>
#include<stdlib.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

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
    mergeSort(arr, 0, number-1);
    for (int i = 0; i < number; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + j + 1];
    }
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}