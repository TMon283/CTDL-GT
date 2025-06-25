#include<stdio.h>
#include<stdlib.h>

int main() {
    int size, target;
    printf("Enter size of array:");
    scanf("%d", &size);
    if (size < 1) {
        printf("Invalid input");
        return 0;
    }
    int *arr= (int*)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    int *arr2= (int*)malloc(size*sizeof(int));
    int count = 0;
    printf("Enter target number:");
    scanf("%d", &target);
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            arr2[count++] = i;
        }
    }
    if (count == 0) {
        printf("Element not found");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", arr2[i]);
        }
    }
    free(arr);
    free(arr2);
    return 0;
}