#include<stdio.h>

void sort(int row, int col, int arr[row][col], int k);

int main() {
    int row, col;
    printf("Enter number of row:");
    scanf("%d", &row);
    printf("Enter number of col:");
    scanf("%d", &col);
    if (row < 1 || col < 1) {
        printf("Invalid input");
        return 0;
    }
    int arr[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("arr[%d][%d] =", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int k;
    printf("Enter k:");
    scanf("%d", &k);
    printf("before:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    sort(row, col, arr, k);
    printf("after:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void sort(int row, int col, int arr[row][col], int k){
    for (int i = 0; i < row - 1; i++) {
        for (int j = 0; j < row - 1 - i; j++) {
            if (arr[j][k] > arr[j+1][k]) {
                int temp = arr[j][k];
                arr[j][k] = arr[j+1][k];
                arr[j+1][k] = temp;
            }
        }
    }
}
