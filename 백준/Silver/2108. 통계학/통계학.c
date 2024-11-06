// 산술평균 : N개의 수들의 합을 N으로 나눈 값
// 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
// 최빈값 : N개의 수들 중 가장 많이 나타나는 값
// 범위 : N개의 수들 중 최댓값과 최솟값의 차이

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b){
    
    int* aa = (int*)a;
    int* bb = (int*)b;
    
    if (*aa > *bb){
        return 1;
    }
    else if (*aa < *bb){
        return -1;
    }
    else{
        return 0;
        
    }
}

// 음수를 생각 못함~!!!
int mode(int maxim[], int sorted_numbers[], int length){
    int max = maxim[0];
    
    int count = 0;
    int memory = 0;
    int result = 0;
    for (int i = 1; i < length; i++){
        if (max < maxim[i]){
            max = maxim[i];
            count = 0;
            result = i;
        }
        else if (max == maxim[i]){
            count++;
            if (count == 1){
                memory = i;
            }
        }
        else{
            count = count;
        }
    }
    if (count == 0){
        return result - 4000;
    }
    else{
        return memory - 4000;
    }
}

int main(void){
    
    int N;
    scanf("%d", &N);
    
    int* numbers = (int*)malloc(sizeof(int) * N);
    int* maxim = (int*)calloc(8001, sizeof(int)); //절댓값이 4000을 넘지 않는다고 했으므로 
    
    double sum = 0; // 평균 연산시 소수점 반올림 해야하므로 double로 선언
    for (int i = 0; i < N; i++){
        scanf("%d", &numbers[i]);
        sum = sum + (double)numbers[i];
        maxim[numbers[i] + 4000]++; // -4000은 0번 인덱스에...
    }
    
    qsort(numbers, N, sizeof(int), compare);
    double avg = sum/N;
    
    if (avg < 0 && (int)avg == 0){ // -0이 있을 거란 생각을 못했다. 그래서 만약 평균이 -0.xxx 일 경우엔
        avg = avg * (-1); // -1 곱해서 양의 0으로 만든다!
    }
    
    printf("%.0f\n", avg); // 산술평균(반올림)
    printf("%d\n", numbers[N/2]); // 중앙값
    printf("%d\n", mode(maxim, numbers, 8001)); // 최빈값
    printf("%d", numbers[N-1] - numbers[0]); // 범위
    
    
    
    
    
}