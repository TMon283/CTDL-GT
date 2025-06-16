#include<stdio.h>
void printAll(int matrix[3][3]);
void printMainDiagonal(int matrix[3][3]);
int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    printAll(matrix);
    printMainDiagonal(matrix);
    return 0;
}
// In toan bo phan tu trong ma tran
void printAll(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}
// Do phuc tap thoi gian: O(n^2)
// Do phuc tap khong gian: O(1)

// In toan bo phan tu tren duong cheo chinh
void printMainDiagonal(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf("%d", matrix[i][i]);
    }
}
// Do phuc tap thoi gian: O(n)
// Do phuc tap khong gian: O(1)
