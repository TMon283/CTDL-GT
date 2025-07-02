#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int n);
int binarySearch(int arr[], int n, int search);

int main() {
    int n, search;
    printf("Enter size of array:");
    scanf("%d", &n);
    if (n <= 0 || n >= 1000) {
        printf("Invalid input");
        return 0;
    }
    int *arr =(int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter element:");
    scanf("%d", &search);
    bubbleSort(arr, n);
    printf("Sorted array:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    int result = binarySearch(arr, n, search);
    if (result == -1) {
        printf("Element not found");
    } else {
        printf("Element found at index: %d", result);
    }
    free(arr);
    return 0;
}

void bubbleSort(int arr[], int number) {
    for (int i = 0; i < number; i++) {
        int swapped = 0;
        for (int j = 0; j < number - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

int binarySearch(int arr[], int n, int search) {
    int min = 0;
    int max = n - 1;
    while (min <= max) {
        int mid = (min + max) / 2;
        if (arr[mid] == search) {
            return mid;
        } else if (arr[mid] < search) {
            min = mid + 1;
        } else {
            max = mid - 1;
        }
    }
    return -1;
}

