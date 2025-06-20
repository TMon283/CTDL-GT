#include<stdio.h>
#include<stdlib.h>

int main () {
    int size;
    printf("Nhap so luong phan tu trong mang");
    scanf("%d", &size);
    if (size <= 0) {
        printf("So luong phan tu khong hop le");
        return 0;
    } else {
        int *arr = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            printf("arr[%d]:", i);
            scanf("%d", &arr[i]);
        }
        int max = arr[0];
        for (int i = 0; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        printf("max = %d\n", max);
        free(arr);
    }
    return 0;
}