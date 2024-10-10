#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int K;
    scanf("%d", &K);
    int length = pow(2, K) - 1; // 완전 이진 트리의 노드 개수
    
    int* arr = (int*)malloc(sizeof(int) * length); // 노드 개수 만큼 배열 생성
    
    for (int i = 0; i < length; i++){
        scanf("%d", &arr[i]); // 배열 값 입력 받기
    }
    
    int num = 1; // num을 1로 설정 (헷갈림 방지)
    int gulf = pow(2, K); // 하위 노드 간 간격 구하기 = 1/2배씩 줄어든다. 그래서 처음엔 트리 전체 개수로 설정.
    while(num <= K){ // K = 2, num = 1, 2
        for (int i = 0; i < pow(2,num-1); i++){ // 트리의 높이 수 만큼 반복: pow(2, num-1) = 트리 높이
            int target = pow(2, K-num)-1; // 출력할 해당 노드의 인덱스 구하기
            if (num == 1){ // 처음에는 무조건 하나만 출력하니 조건문으로 하나만 출력하도록 설정
                printf("%d", arr[target]);
                arr[target] = -1; // 출력한 건 -1로 설정
            }
            else{ // 그 이후부터는
                if (arr[target] == -1){ // -1로 체크된 값이 있으면, 이미 출력된 것이므로
                    target = target+(gulf*i); // target을 gulf만큼 더한 위치에 있는 노드 출력
                    printf("%d ", arr[target]); //출력
                    arr[target] = -1; //출력하고 -1로 바꿈
                }
                else{ // -1이 아니면 아직 출력 안한 새 노드
                    printf("%d ", arr[target]); //출력하고
                    arr[target] = -1; // -1로 바꿈
                }
            }
        }
        gulf = gulf / 2; // 하위노드로 내려갈 수록 간격은 1/2배가 됨.
        printf("\n");
        num++; // 반복문 작동을 위해 num 증가
    }
}
