#include<stdio.h>
#include<stdlib.h>

int main() {
    int size;
    printf("Nhap so luong phan tu cua mang");
    scanf("%d", &size);
    if (size < 0) {
        printf("So luong phan tu khong duoc am\n");
        return 1;
    } else if (size == 0) {
        printf("So luong phan tu phai lon hon 0\n");
        return 1;
    } else {
        int *arr = (int*)malloc(size * sizeof(int));
        if (arr == NULL) {
            printf("Loi bo nho\n");
            return 1;
        }
        for (int i = 0; i < size; i++) {
            printf("arr[%d]:", i);
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < size; i++) {
            printf("So thu %d = %d\n", i+1, arr[i]);
        }
        free(arr);
    }
    return 0;
}