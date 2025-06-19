#include<stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    if (size <= 0 || size > 100) {
        printf("Invalid input");
        return 1;
    }
    int *arr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int position, value;
    printf("Enter element position: ");
    scanf("%d", &position);
    if (position < 1 || position > 100 || position > size) {
        printf("Invalid input");
    } else {
        printf("Enter element value: ");
        scanf("%d", &value);
        arr = (int*)realloc(arr, (size + 1)*sizeof(int));
        for (int i = size; i > position; i--) {
            arr[i] = arr[i-1];
        }
        arr[position] = value;
        size++;
        for (int i = 0; i < size; i++) {
            if (i == size - 1) {
                printf("%d", arr[i]);
            } else {
                printf("%d, ", arr[i]);
            }
        }
    }
    free(arr);
    return 0;
}
