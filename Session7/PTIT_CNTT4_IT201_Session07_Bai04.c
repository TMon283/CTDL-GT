#include <ctype.h>
#include<stdio.h>
#include<string.h>

void sortChar(char *str);

int main() {
    char str[256];
    printf("Enter string:");
    fgets(str, 256, stdin);
    str[strcspn(str, "\n")] = 0;
    if (strlen(str) == 0) {
        printf("String invalid");
        return 0;
    }
    printf("before: \"%s\"\n", str);
    sortChar(str);
    printf("after: \"%s\"\n", str);
    return 0;
}

void sortChar(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tolower(str[i]) > tolower(str[j])) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}