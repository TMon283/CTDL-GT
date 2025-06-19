#include<stdio.h>
#include<stdlib.h>

int findTwoElementsSum(int arr[], int size, int value);

int main() {
    int size, value;
    printf("Enter size of array: ");
    scanf("%d", &size);
    if (size < 0) {
        printf("Invalid input");
        return 1;
    }
    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation error");
        return 1;
    }
    for (int i = 0; i < size; i ++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter value to be sum: ");
    scanf("%d", &value);
    int result = findTwoElementsSum(arr, size, value);
    if (result == 1) {
        printf("Can't find");
    }
    free(arr);
    return 0;
}

int findTwoElementsSum(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        int result = value - arr[i];
        for (int j = i + 1; j < size; j++) {
            if (result == arr[j]) {
                printf("%d, %d", arr[i], arr[j]);
                return 0;
            }
        }
    }
    return 1;
}