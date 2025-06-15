#include<stdio.h>

int main(){
	int* mallocArray(int n) {
		int* arr = (int*)malloc(n * sizeof(int));
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
		return arr;
	}
	return 0;
}

//Phan cap phat dong có do phuc tap là O(n) vì mang co n phan tu
//Cac bien tam thoi trong vong lap for có do phuc tap O(1) vi chung khong phu thuoc vao n
//=> Do phuc tap khong gian cua doan ma nay la O(n) vi kich thuoc mang tang tuyen tinh theo n

