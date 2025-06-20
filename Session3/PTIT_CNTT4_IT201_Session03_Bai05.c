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
                mainDiagonal += arr[i][i];
                minorDiagonal += arr[i][cols - 1 - i];
            }
            printf("Tong duong cheo chinh = %d\n", mainDiagonal);
            printf("Tong duong cheo phu = %d\n", minorDiagonal);
        }
    }
    return 0;
}