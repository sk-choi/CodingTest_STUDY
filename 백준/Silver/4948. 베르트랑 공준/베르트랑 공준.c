#include <stdio.h>
#include <math.h>
#define SIZE 246913 //입력 받은 수의 두 배 범위까지 출력하므로 0포함해서 123,456 * 2 + 1

int main(void){
    
    int prime[SIZE] = {};
    int Bertrand[SIZE] = {}; 
    
    for (int i = 2; i < sqrt(SIZE); i++){
        if (prime[i] == 0){
            for (int j = 2; i * j < SIZE; j++){
                prime[i * j] = 1;
            }
        }
    }
    prime[0] = 1;
    prime[1] = 1;
    
    int count = 0;
    for (int j = 0; j < SIZE; j++){
        if (prime[j] == 0){
            count++;
            Bertrand[j] = count;
        }
        else{
            Bertrand[j] = count;
        }
    }
    
    while(1){
        
        int num;
        scanf("%d", &num);
        if (num == 0){
            break;
        }
        else{
            printf("%d\n", Bertrand[2*num] - Bertrand[num]);
        }
    }
    
}