#include<stdio.h>
#include<string.h>

int main() {
    char str1[] = "hello";
    char str2[] = "olhel";
    int count[256] = {0};
    int result = 1;
    if (strlen(str1) != strlen(str2)) {
        result = 0;
    }
    for (int i = 0; i < strlen(str1); i++) {
        count[str1[i]]++;
        count[str2[i]]--;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            result = 0;
            break;
        }
    }
    if (result == 1) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}
// Do phuc tap thuat toan: O(n)