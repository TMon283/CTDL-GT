#include<stdio.h>

int main() {
    int array[] = {3, 4, 1, 7, 2, 3, 5, 0, -2, 9};
    int result = -1;
    // Cach 1: Do phuc tap thuat toan: O(n^2)
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        for (int j = i + 1; j < sizeof(array)/sizeof(array[0]); j++) {
            if (array[i] == array[j]) {
                result = 1;
            }
        }
    }
    // Cach 2: Do phuc tap thuat toan: O(n^2)
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        for (int j = i + 1; j < sizeof(array)/sizeof(array[0]); j++) {
            if (array[i] > array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for (int i = 1; i < sizeof(array)/sizeof(array[0]); i++) {
        if (array[i] == array[i+1] || array[i] == array[i-1]) {
            result = 1;
        }
    }
    // Cach 3: Do phuc tap thuat toan: O(n)
    int array2[100] = {0};
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        array2[array[i]]++;
        if (array2[array] > 1) {
            result = 1;
        }
    }
    return 0;
}