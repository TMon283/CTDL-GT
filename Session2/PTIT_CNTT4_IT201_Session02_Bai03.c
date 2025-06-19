#include<stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("Invalid input");
        return 1;
    }
    int *arr = (int *)malloc(n * sizeof(int));
    int *reverseArr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n; i++) {
        reverseArr[i] = arr[n - i - 1];
    }
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", reverseArr[i]);
        } else {
            printf("%d, ", reverseArr[i]);
        }
    }
    free(arr);
    free(reverseArr);
    return 0;
}
