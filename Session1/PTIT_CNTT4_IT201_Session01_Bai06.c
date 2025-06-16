#include<stdio.h>

int main() {
    int array[] = {1, 3, 4, 3, 5, 9, 6, 3};
    int n, count;
    printf("Input the number: ");
    scanf(%d, &n);
    for (int i = 0; i < array.length; i++) {
        if (array[i] == n) {
            count++;
        }
    }
    return 0;
}

// Do phuc tạp thuat toan la O(n)