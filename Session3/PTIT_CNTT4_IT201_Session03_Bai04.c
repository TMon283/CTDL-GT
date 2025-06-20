#include<stdio.h>

int main() {
    int rows, cols;
    printf("Nhap so hang:");
    scanf("%d", &rows);
    printf("Nhap so cot:");
    scanf("%d", &cols);
    if (rows > 0 && cols <= 0) {
        printf("So cot khong hop le");
        return 1;
    } else if (rows <= 0 && cols > 0) {
        printf("So hang khong hop le");
        return 1;
    } else if (rows < 0 && cols < 0) {
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
        int max = arr[0][0];
        int min = arr[0][0];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (arr[i][j] > max) {
                    max = arr[i][j];
                }
                if (arr[i][j] < min) {
                    min = arr[i][j];
                }
            }
        }
        printf("max=%d\n", max);
        printf("min=%d\n", min);
    }
    return 0;
}