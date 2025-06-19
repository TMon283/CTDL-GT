#include<stdio.h>
#include <stdlib.h>

void deleteElement(int arr[], int n);
int main () {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid input");
        return 1;
    }
    int *arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    deleteElement(arr, n);
    free(arr);
    return 0;
}
void deleteElement(int arr[], int n) {
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);
    if (position < 0 || position > n) {
        printf("Invalid input\n");
        return;
    } else {
        int *arr2 = (int*)realloc(arr, (n-1)*sizeof(int));
        if (arr2 == NULL) {
            printf("Memory allocation error\n");
            return;
        }
        arr = arr2;
        for (int i = position; i < n; i++) {
            arr[i] = arr[i+1];
        }
        n--;
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                printf("%d", arr[i]);
            } else {
                printf("%d, ", arr[i]);
            }
        }
    }
}