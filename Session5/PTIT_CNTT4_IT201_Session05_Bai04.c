#include<stdio.h>

int findSum(int firstNum, int secondNum);

int main() {
    int firstNum, secondNum;
    printf("Enter first number:");
    scanf("%d", &firstNum);
    printf("Enter second number:");
    scanf("%d", &secondNum);
    if (firstNum < 0 || secondNum < 0) {
        printf("Invalid input");
        return 0;
    }
    if (firstNum == secondNum) {
        printf("Output:%d", firstNum);
        return 0;
    }
    if (firstNum > secondNum) {
        int temp = firstNum;
        firstNum = secondNum;
        secondNum = temp;
    }
    int result = findSum(firstNum, secondNum);
    printf("Output:%d",result);
    return 0;
}

int findSum(int firstNum, int secondNum) {
    if (firstNum == secondNum) return secondNum;
    return secondNum + findSum(firstNum, secondNum - 1);
}