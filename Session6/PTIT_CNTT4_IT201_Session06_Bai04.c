#include<stdio.h>

void move(int number, char from, char to);
void towerSort(int number, char from, char temp, char to);

int main() {
    int number;
    printf("Enter number of place:");
    scanf("%d", &number);
    if (number <= 0) {
        printf("Invalid input");
        return -1;
    }
    towerSort(number, 'A', 'B', 'C');
    return 0;
}

void move(int number, char from, char to) {
    printf("Dia %d di chuyen tu %c sang %c\n", number, from, to);
}

void towerSort(int number, char from, char temp, char to) {
    if (number == 1) {
        move(1, from, to);
        return;
    }
    towerSort(number - 1, from, to, temp);
    move(number, from, to);
    towerSort(number - 1, temp, from, to);
}