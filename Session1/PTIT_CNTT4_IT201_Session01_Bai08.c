#include<stdio.h>

int main() {
    int array[] = {0, 2, 1, 0, 2, 4, 5, 9, 7, 0, 3, 6};
    for (int i = 0; i < array.length; i++) {
        for (int j = i + 1; j < array.length; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    int maxCount = 0, currentCount = 1;
    int maxElement = array[0], currentElement = array[0];
    for (int i = 0; i < array.length; i++) {
        if (array[i] == currentElement) {
            currentCount++;
        } else {
            currentElement = array[i];
        }
        if (currentCount > maxCount) {
            maxtCount = currentCount;
            maxElement = array[i];
        }
    }
    return 0;
}

//Do phuc tap cua phan tu la O(n^2)