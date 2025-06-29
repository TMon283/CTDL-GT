#include<stdio.h>

int combination(int n, int k);
int countWaysToClimb(int n, int i);

int main() {
    int number;
    printf("Enter number of the staircase:");
    scanf("%d", &number);
    if (number < 1) {
        printf("Invalid input");
        return 0;
    }
    printf("The number of ways to climb the stairs is:%d", countWaysToClimb(number, 0));
    return 0;
}

int combination(int n, int k) {
    if (k > n) return 0;
    if (k > n - k) k = n - k;
    int result = 1;
    for (int i = 1; i <= k; i++) {
        result = result * (n - k + i) / i;
    }
    return result;
}

int countWaysToClimb(int n, int i) {
    if (2*i > n) return 0;
    return combination(n - i, i) + countWaysToClimb(n, i + 1);
}