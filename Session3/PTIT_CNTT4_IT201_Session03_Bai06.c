#include<stdio.h>
#include<stdlib.h>

int main() {
    int n;
    printf("n=");
    scanf("%d", &n);
    if (n < 0) {
        printf("So luong phan tu khong phu hop");
        return 1;
    }
    int *arr =(int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    int m;
    printf("m=");
    scanf("%d", &m);
    if (m < 0) {
        printf("So luong phan tu khong hop le");
        return 0;
    }
    arr = (int*)realloc(arr, (n + m) * sizeof(int));
    for (int i = n; i < n + m; i++) {
        printf("arr[%d]=", i);
        scanf("%d", &arr[i]);
    }
    printf("[");
    for (int i = 0; i < n + m; i++) {
        if (i < n + m - 1) {
            printf("%d, ", arr[i]);
        } else {
            printf("%d]", arr[i]);
        }
    }
    free(arr);
    return 0;
}
