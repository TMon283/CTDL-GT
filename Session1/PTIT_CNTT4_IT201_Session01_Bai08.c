#include<stdio.h>

int main() {
    int array[] = {0, 2, 1, 0, 2, 4, 5, 9, 7, 0, 3, 6};
    int maxCount = 0, currentCount = 1;
    int maxElement = array[0], currentElement = array[0];
    for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++) {
        if (array[i] == currentElement) {
            currentCount++;
        } else {
            currentElement = array[i];
        }
        if (currentCount > maxCount) {
            maxCount = currentCount;
            maxElement = array[i];
        }
    }
    if (maxCount > 0) {
        printf("Phan tu xuat hien nhieu nhat la: %d\n", maxElement);
    } else {
        printf("Mang rong\n");
    }
    return 0;
}

//Do phuc tap cua phan tu la O(n)