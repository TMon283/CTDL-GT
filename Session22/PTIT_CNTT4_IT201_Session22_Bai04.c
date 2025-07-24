#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0 || n >= 100) {
        printf("Invalid input\n");
        return 1;
    }
    int matrix[100][100];
    int i, j, count = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (matrix[i][j] == 1) {
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}