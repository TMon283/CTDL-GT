#include <ctype.h>
#include<stdio.h>
#include<string.h>

int changeStringToNum(char input[100], int length);

int main() {
    char input[100];
    printf("Enter input:");
    scanf("%s", input);
    int length = (int)strlen(input);
    for (int i = 0; i < length; i++) {
        if (!isdigit((unsigned char)input[i])) {
            printf("Invalid input");
            return 0;
        }
    }
    int start = 0;
    while (start < length - 1 && input[start] == '0') {
        start++;
    }
    int result = changeStringToNum(input, length);
    printf("The number is : %d", result);
    return 0;
}

int changeStringToNum(char input[100], int length) {
    if (length == 1) return input[0] - '0';
    return changeStringToNum(input, length - 1) * 10 + input[length - 1] - '0';
}