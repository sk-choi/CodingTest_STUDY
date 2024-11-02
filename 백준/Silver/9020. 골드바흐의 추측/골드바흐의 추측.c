#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10001

void Eratosthenes(int arr[]){
    
    for (int i = 2; i <= sqrt(SIZE); i++){
        if (arr[i] == 0){
            for (int j = 2; i * j < SIZE; j++){ // i * j 가 중요합니다!!!!
                arr[i*j] = 1;
            }
        }
    }
}


int main(void){
    
    int N;
    scanf("%d", &N);
    int* prime = (int*)calloc(SIZE, sizeof(int)); // 0으로 초기화
    Eratosthenes(prime);
    
    for(int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);
        int left = num / 2;
        int right = num / 2;
        for (int j = 0; j < num; j++){
            if(left+right == num && prime[left] == 0 && prime[right] == 0){
                printf("%d %d\n", left, right);
                break;
            }
            else{
                left--;
                right++;
            }
        }
    }
    
    
}