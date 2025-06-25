#include<stdio.h>
#include<stdlib.h>

void findSymmetricElement(int arr[], int size);

int main() {
    int size;
    printf("Enter the size of array:");
    scanf("%d", &size);
    if (size < 1) {
        printf("Invalid input");
        return 0;
    }
    int *arr = (int*)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    findSymmetricElement(arr, size);
    free(arr);
    return 0;
}

void findSymmetricElement(int arr[], int size) {
    int arr2[size/2];
    int count = 0;
    for (int i = 0; i < size/2; i++) {
        if (arr[i] == arr[size - 1 - i]) {
            arr2[count] = arr[i];
            count++;
        }
    }
    if (count == 0) {
        printf("Khong co phan tu doi xung");
    } else {
        for (int i = 0; i < count; i++) {
            printf("Cap doi xung (%d, %d)\n", arr2[i], arr2[i]);
        }
    }
}