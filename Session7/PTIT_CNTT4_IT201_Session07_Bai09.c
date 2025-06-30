#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int n);
void bubbleSort(int arr[], int n);

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
        if (arr[i] <= 0) {
            printf("Invalid input");
            free(arr);
            return 0;
        }
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
    int oddCount = 0, evenCount = 0;
    int oddArr[n], evenArr[n];
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evenArr[evenCount++] = arr[i];
        } else {
            oddArr[oddCount++] = arr[i];
        }
    }
    int index = 0;
    bubbleSort(oddArr, oddCount);
    bubbleSort(evenArr, evenCount);
    for (int i = 0; i < evenCount; i++) {
        arr[index++] = evenArr[i];
    }
    for (int i = oddCount - 1; i >= 0; i--) {
        arr[index++] = oddArr[i];
    }
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