#include<stdio.h>

int findTheWayInMatrix(int i, int j, int r, int c, int blockRow, int blockCol);

int main() {
    int row, col, blockRow, blockCol;
    printf("Enter number of rows:");
    scanf("%d", &row);
    printf("Enter number of cols:");
    scanf("%d", &col);
    printf("Enter row of block:");
    scanf("%d", &blockRow);
    printf("Enter col of block:");
    scanf("%d", &blockCol);
    if (row < 1 || col < 1 || blockRow < 1 || blockCol < 1 || blockRow > row || blockCol > col) {
        printf("Invalid input");
        return 0;
    }
    if (blockCol == 0 && blockRow == 0) {
        printf("Output:0");
        return 0;
    }
    int i, j;
    int r = row - 1;
    int c= col - 1;
    int result = findTheWayInMatrix(0, 0, r, c, blockRow, blockCol);
    printf("Output:%d", result);
    return 0;
}

int findTheWayInMatrix(int i, int j, int r, int c, int blockRow, int blockCol) {
    if (i == c && j == r) return 1;
    if ((i == blockRow && j == blockCol) || i > c || j > r) return 0;
    return findTheWayInMatrix(i + 1, j, r, c, blockRow, blockCol) + findTheWayInMatrix(i, j + 1, r, c, blockRow, blockCol);
}