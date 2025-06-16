#include<stdio.h>
void findSum1(int n);
void findSum2(int n);
int main(){
	int n, choice;
	do {
		printf("1. Cach 1\n");
		printf("2. Cach 2\n");
		printf("3. Thoat menu\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		system("cls");
		switch(choice){
			case 1:
				printf("Input n: ");
				scanf("%d", &n);
				findSum1(n);
				break;
			case 2: 
				printf("Input n: ");
				scanf("%d", &n);
				findSum2(n);
				break;
			case 3:
				printf("Thoat chuong trinh");
				break;
			default:
				printf("Thao tac khong hop le");
		}
	} while(choice != 3);
	return 0;
}

void findSum1(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i;	
	}
	printf("Output: %d\n\n", sum);
}
//Do phuc tap thoi gian: O(n)
//Do phuc tap khong gian: O(1)

void findSum2(int n) {
	int sum = n * (n + 1) / 2;
	printf("Output: %d\n\n", sum);
}
//Do phuc tap thoi gian: O(1)
//Do phuc tap khong gian: O(1)

