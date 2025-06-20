#include<stdio.h>
#include<stdlib.h>

void findMostFrequent(int arr[], int size);

int main() {
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    if (size <= 0) {
        printf("Invalid input");
        return 1;
    }
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    findMostFrequent(arr, size);
    free(arr);
    return 0;
}

void findMostFrequent(int arr[], int size) {
    int maxFrequentCount = 0;
    int maxFrequentElement = arr[0];
    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxFrequentCount) {
            maxFrequentElement = arr[i];
            maxFrequentCount = count;
        }
    }
    printf("Output: %d", maxFrequentElement);
}