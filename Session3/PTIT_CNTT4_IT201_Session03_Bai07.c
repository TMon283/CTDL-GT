#include<stdio.h>

int main() {
    int rows, cols;
    printf("Nhap so hang:");
    scanf("%d", &rows);
    printf("Nhap so cot:");
    scanf("%d", &cols);
    if (rows > 0 && cols <= 0 || cols > 1000) {
        printf("So cot khong hop le");
        return 1;
    } else if (rows <= 0 || rows > 1000 && cols > 0) {
        printf("So hang khong hop le");
        return 1;
    } else if (rows < 0 | rows > 1000 && cols < 0 || cols > 1000) {
        printf("So cot va hang khong hop le");
        return 1;
    } else {
        int arr[rows][cols];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("arr[%d][%d]=", i, j);
                scanf("%d", &arr[i][j]);
            }
        }
        int k;
        printf("Nhap hang ban muon tinh tong");
        scanf("%d", &k);
        if (k > rows + 1 || k <= 0) {
            printf("So hang khong ton tai");
            return 1;
        } else {
            int sum = 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i + 1 == k) {
                        sum += arr[i][j];
                    }
                }
            }
            printf("sum=%d", sum);
        }
    }
    return 0;
}