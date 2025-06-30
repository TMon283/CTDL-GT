#include<stdio.h>
#include <stdlib.h>

void sort(int arr[], int n);

int main() {
    int n;
    printf("Enter size of array:");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input");
        return 0;
    }
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d] =", i);
        scanf("%d", &arr[i]);
    }
    printf("before:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nafter:");
    sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}

void sort(int arr[], int n) {
    int negCount = 0, posCount = 0, zeroCount = 0;
    int negArr[n], posArr[n], zeroArr[n];
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            negArr[negCount++] = arr[i];
        } else if (arr[i] == 0) {
            zeroArr[zeroCount++] = arr[i];
        } else {
            posArr[posCount++] = arr[i];
        }
    }
    int index = 0;
    for (int i = negCount - 1; i >= 0 ; i--) {
        arr[index++] = negArr[i];
    }
    for (int i = 0; i < zeroCount; i++) {
        arr[index++] = zeroArr[i];
    }
    for (int i = posCount - 1; i >= 0 ; i--) {
        arr[index++] = posArr[i];
    }
}