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
                printf("arr[%d][%d]:", i, j);
                scanf("%d", &arr[i][j]);
            }
        }
        if (rows != cols) {
            printf("Khong ton tai duong cheo chinh\n");
            printf("Khong ton tai duong cheo phu\n");
        } else {
            int mainDiagonal = 0;
            int minorDiagonal = 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i == j) {
                        mainDiagonal += arr[i][i];
                    }
                    if (i + j == cols - 1) {
                        minorDiagonal += arr[i][j];
                    }
                }
            }
            printf("Tong duong cheo chinh = %d\n", mainDiagonal);
            printf("Tong duong cheo phu = %d\n", minorDiagonal);
        }
    }
    return 0;
}