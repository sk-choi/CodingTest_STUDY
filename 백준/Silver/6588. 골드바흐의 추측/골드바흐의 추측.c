#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 1000001

int main() {
    
    int n;
    int* prime = (int*)calloc(SIZE, sizeof(int));
    
    for (int i = 2; i < sqrt(SIZE); i++){
        if (prime[i] == 0){
            for (int j = 2; j * i < SIZE; j++){
                prime[i * j] = 1;
            }
        }
    }    
    prime[0] = 1;
    prime[1] = 1;

    while(1){
        
        scanf("%d", &n);
        if (n == 0){
            break;
        }
        else{
            int left = 1;
            int right = n-1;
            for (int k = 0; k < n/2; k++){
                if (left+right == n && prime[left] == 0 && prime[right] == 0){
                    printf("%d = %d + %d\n", n, left, right);
                    break;
                }
                else{
                    left++;
                    right--;
                }
                if (right < left){
                    printf("Goldbach's conjecture is wrong.\n");
                    break;
                }
            }
        }
    }
}