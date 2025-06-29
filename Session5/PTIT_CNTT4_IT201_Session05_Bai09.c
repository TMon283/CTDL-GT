#include<stdio.h>

int findTheWayInMatrix(int row, int col);

int main() {
    int row, col;
    printf("Enter rows:");
    scanf("%d", &row);
    printf("Enter cols:");
    scanf("%d", &col);
    if (row < 1 || col < 1) {
        printf("Invalid input");
        return 0;
    }
    int result = findTheWayInMatrix(row - 1, col - 1);
    printf("Output:%d", result);
    return 0;
}

int findTheWayInMatrix(int row, int col) {
    if (col == 0 || row == 0) return 1;
    return findTheWayInMatrix(row - 1, col) + findTheWayInMatrix(row, col - 1);
}