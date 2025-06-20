#include<stdio.h>
#include<stdlib.h>

int main() {
    int size;
    printf("Nhap so luong phan tu muon them vao mang");
    scanf("%d", &size);
    if (size <= 0) {
        printf("So luong phan tu khong hop le");
        return 1;
    } else {
        int *arr = (int*)malloc(size * sizeof(int));
        if (arr == NULL) {
            printf("Loi bo nho");
            return 1;
        }
        for (int i = 0; i < size; i++) {
            printf("arr[%d]:", i);
            scanf("%d", &arr[i]);
        }
        int count = 0;
        int sum = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 0) {
                sum += arr[i];
                count++;
            }
        }
        printf("Average = %d", (sum/count));
    }
    return 0;
}