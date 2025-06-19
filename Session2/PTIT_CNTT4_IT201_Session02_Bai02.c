#include<stdio.h>

int main() {
    int n, number;
    int count = 0;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    if (n <= 0 || n > 100) {
        printf("invalid input");
        return 1;
    }
    int *arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter number: ");
    scanf("%d", &number);
    for (int i = 0; i < n; i++) {
        if (arr[i] == number) {
            count++;
        }
    }
    printf("Output: %d", count);
    free(arr);
    return 0;
}