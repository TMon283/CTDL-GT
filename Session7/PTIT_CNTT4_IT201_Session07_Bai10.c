#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int value;
    int distance;
} Distance;

void sortByDistance(Distance arr[], int n);

int main() {
    int n, X;
    printf("Enter number of elements:");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid input");
        return 0;
    }
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr == NULL) {
        printf("Error allocating memory");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("Enter distance:");
    scanf("%d", &X);
    Distance *arr2 = malloc(n*sizeof(Distance));
    for (int i = 0; i < n; i++) {
        arr2[i].value = arr[i];
        arr2[i].distance = abs(arr[i] - X);
    }
    printf("Distance to X:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i].distance);
    }
    printf("\n");
    sortByDistance(arr2, n);
    for (int i = 0; i < n; i++) {
        arr[i] = arr2[i].value;
    }
    printf("Output:");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    free(arr2);
    free(arr);
    return 0;
}

void sortByDistance(Distance arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].distance < arr[min].distance || arr[j].distance == arr[min].distance && arr[j].value < arr[min].value) {
                min = j;
            }
        }
        if (min != i) {
            Distance temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}