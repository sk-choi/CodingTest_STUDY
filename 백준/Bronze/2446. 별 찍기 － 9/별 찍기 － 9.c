#include <stdio.h>

void printstar(int n){
    
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= i; j++){
            printf(" ");
        }
        for (int j = 1; j <= (2 * n) - ((2 * i)+1); j++){
            printf("*");
        }
        printf("\n");
    }
    for (int i = 1; i <= n-1; i++){
        for (int k = n-2; k >= i; k--){
            printf(" ");
        }
        for (int k = 1; k <= (2 * i) + 1; k++){
             printf("*");
        }
        printf("\n");
    }
    
    
}

int main(void){
 
    int N;
    scanf("%d", &N);
    printstar(N);
}