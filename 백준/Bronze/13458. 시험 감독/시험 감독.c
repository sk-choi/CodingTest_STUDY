#include <stdio.h>
#include <stdlib.h>

int main(void){
    
    int N; // 시험장 개수
    int master; // 총감독관 감시 가능 인원.
    int sub; // 감독관 감시 가능 인원.
    
    scanf("%d", &N);
    
    int* arr = (int*)malloc(sizeof(int) * N);
    
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    
    scanf("%d %d", &master, &sub);
    
    long long int count = 0;
    
    for (int i = 0; i < N; i++){
        
        arr[i] = arr[i] - master;
        
        if (arr[i] < 0){ // master 뺀 값이 0보다 작으면 0으로 변경.
            arr[i] = 0;
        }
        count++;
        
        
        if (arr[i] != 0){
            if (arr[i] % sub != 0){ // 감독관 감시 인원 가능 수로 나눈 나머지가 0이 아니면
        
                count += (arr[i] / sub) + 1; // 1명 더 추가
            }
            else{
                count += (arr[i] / sub); // 아니면 그냥 몫만 더하기.
            }
        }
        
    }
    
    
    printf("%lld", count);
    
    
}