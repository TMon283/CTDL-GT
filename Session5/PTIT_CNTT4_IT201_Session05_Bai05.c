#include<stdio.h>
#include<string.h>

int checkSymmetry(char input[], int i, int length);

int main() {
    char input[20];
    printf("Enter a string:");
    scanf("%s", &input);
    int length = strlen(input);
    int i = 0;
    if (checkSymmetry(input, i , length)) {
        printf("Palindrome valid");
    } else {
        printf("Palindrome invalid");
    }
    return 0;
}

int checkSymmetry(char input[], int i, int length) {
    if (i >= length / 2) return 1;
    if (input[i] == input[length - 1 - i]) {
        return checkSymmetry(input, i + 1, length);
    } else {
        return 0;
    }
}