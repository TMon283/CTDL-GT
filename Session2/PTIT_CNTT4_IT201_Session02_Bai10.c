#include<stdio.h>
#include<stdlib.h>

void printFrequentOfElement(int arr[], int size);
int isAppeared(int arr[], int index);

int main () {
    int size;
    printf("Enter the size of array:");
    scanf("%d", &size);
    if (size < 0) {
        printf("Invalid input");
        return 1;
    }
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("arr[%d]:", i);
        scanf("%d", &arr[i]);
    }
    printFrequentOfElement(arr, size);
    free(arr);
    return 0;
}

int isAppeared(int arr[], int index) {
    for (int i = 0; i < index; i++) {
        if (arr[i] == arr[index]) {
            return 1;
        }
    }
    return 0;
}

void printFrequentOfElement(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (isAppeared(arr, i)) {
            continue;
        }
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        printf("Phan tu %d xuat hien %d lan\n", arr[i], count);
    }
}

