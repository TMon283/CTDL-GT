#include<stdio.h>
#include <stdlib.h>

int main() {
    int n, position, value;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid input");
        return 1;
    }
    int *arr = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ",i);
        scanf("%d", &arr[i]);
    }
    printf("Enter position: ");
    scanf("%d", &position);
    printf("Enter value: ");
    scanf("%d", &value);
    arr[position] = value;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", arr[i]);
        } else {
            printf("%d, ", arr[i]);
        }
    }
    free(arr);
    return 0;
}
