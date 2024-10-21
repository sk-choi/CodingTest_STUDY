#include <stdio.h>
#include <stdlib.h>

// 생각해보니 어차피 출력하는 것은 정렬된 원소니까 입력받은 개수대로 출력을 하면 된다.
// 무조건 반복을 10000번 돌릴 필요가 없었다.
void frequency_count(int B[], int len){
    for (int k = 1; k <= 10000; k++){
        
        if (B[k] > 0){
            printf("%d\n", k);
            B[k]--;
        }
            
        if (B[k] > 0){
            k--;
        }
    }
}

int main(void){
    
    int N;
    scanf("%d", &N);
    
    int A;
    
    int B[10001] = {0,};
    
    for (int i = 0; i < N; i++){
        scanf("%d", &A);
        B[A]++;
    }
    
    frequency_count(B, N);
    
}