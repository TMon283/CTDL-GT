#include<stdio.h>

int main() {
    int rows, cols;
    printf("Enter rows:");
    scanf("%d", &rows);
    printf("Enter cols:");
    scanf("%d", &cols);
    if (rows != cols || rows < 0 || cols < 0) {
        printf("Can't make square matrix");
        return 1;
    }
    int matrix[rows][cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("matrix[%d][%d]:", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    int arr[100];
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || j == 0 || i == rows - 1 || j == cols - 1) {
                arr[count] = matrix[i][j];
                count++;
            }
        }
    }
    for (int i = 0; i < count; i++) {
        for (int j = i + 1; j < count; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j != cols - 1) {
                matrix[i][j] = arr[count];
                count++;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (j == cols - 1 && i != rows - 1) {
                matrix[i][j] = arr[count];
                count++;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = cols - 1; j >= 0; j--) {
            if (i == cols - 1 && j != 0) {
                matrix[i][j] = arr[count];
                count++;
            }
        }
    }
    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 0; j--) {
            if (j == 0 && i != 0) {
                matrix[i][j] = arr[count];
                count++;
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}