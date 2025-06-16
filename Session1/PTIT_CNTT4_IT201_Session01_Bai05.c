#include<stdio.h>

int main(){
    int array[] = {5, 2, 3, 1, 6};
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            if(array[i] > array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return 0;
}

// Do phuc tap thuat toan la O(n^2)