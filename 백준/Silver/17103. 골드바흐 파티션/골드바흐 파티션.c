#include <stdio.h>
#include <math.h>
#define SIZE 1000001

int main(void){
    
    int N;
    scanf("%d", &N);
    
    int prime[SIZE] = {};
    int gold_pt[SIZE] = {};
    
    for (int i = 2; i <= sqrt(SIZE); i++){
        if (prime[i] == 0){
            for (int j = 2; i * j <= SIZE; j++){
                prime[i * j] = 1;
            }
        }
    }
    
    prime[0] = 1;
    prime[1] = 1;
    
    for (int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);
        
        int left = num/2;
        int right = num/2;
        int count = 0;
        for (int j = 0; j < num/2; j++){
            if (left+right == num && prime[left] == 0 && prime[right] == 0){
                count++;
                gold_pt[num] = count;
            }
            left--;
            right++;
        }
        printf("%d\n", gold_pt[num]);   
    } 
}
