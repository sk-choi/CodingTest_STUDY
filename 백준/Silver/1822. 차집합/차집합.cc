#include <stdio.h>
#include <stdlib.h>
#include <cassert>


int compare(const void* a, const void* b){ //정렬을 위한 compare 함수 선언
    
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

int main(void){
    
    int A, B;
    
    scanf("%d %d", &A, &B);
    
    int* arrA = (int*)malloc(sizeof(int)* A); // A집합 원소 저장할 배열 선언
    int* arrB = (int*)malloc(sizeof(int)* B); // B집합 원소 저장할 배열 선언
    int* result = (int*)malloc(sizeof(int)* A); // 차집합 결과 저장할 배열 선언
    for (int i = 0; i < A; i++){ // A원소 입력 받기
        int num;
        scanf("%d", &num);
        assert(num > 0);
        arrA[i] = num;
    }
    
    for (int i = 0; i < B; i++){ // B원소 입력 받기
        int num;
        scanf("%d", &num);
        assert(num > 0);
        arrB[i] = num;
    }
    
    qsort(arrA, A, sizeof(int), compare); // 퀵 소트를 통한 정렬
    qsort(arrB, B, sizeof(int), compare);
    
    int count = 0;
    int index = 0;
    for (int j = 0; j < A; j++){
        int search = arrA[j];
        if(bsearch(&search, arrB, B, sizeof(int), compare) == NULL){ 
            // 만약 집합B의 원소가 A에 없으면 
            result[index++] = search; // 결과 저장하는 배열에 해당 값 넣기
        }
        else{
            count++; // 있다면 카운트 +1 증가
        }
    }
    
    if (count == A){ // 카운트와 A크기가 같으면 0 출력
        printf("%d", 0);
    }
    else{ // 다르다면
        printf("%d\n", A - count); // 차집합 원소 개수 출력하고
        for (int i = 0; i < A-count; i++){
            printf("%d ", result[i]); // 해당 결과 원소 출력
        }
    }
    
}