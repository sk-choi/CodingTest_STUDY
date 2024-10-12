#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 시간 초과 이유: strlen이 O(n)이라서 반복문에 사용할 경우 O(n^2)이 된다.

int main() {
    char word[1000001] = {};
    char alpha[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int many[26] = {0,}; // 0 = 'A',..., 26 = 'Z'
    scanf("%s", word);
    
    int len = strlen(word);
    
    // 문자열 대문자로 변환
    for (int i = 0; i < len; i++){
        if (word[i] >= 'a' && word[i] <= 'z'){
            word[i] -= 32;
        }
    }
    
    // 가장 많은 수의 알파벳 위치에 1씩 추가
    for (int i = 0; i < len; i++){
        many[word[i]-65]++;
    }
    
    // 최대값 찾기
    int max  = many[0];
    for (int i = 1; i < sizeof(many)/sizeof(int); i++){
        if (max < many[i]){
            max = many[i];
        }
    }
    //printf("%d", max);
    
    // 최대값과 동일한 값 있으면 flag 1 증가
    // 해당 위치 정보 locate에 저장
    int flag = 0;
    int locate = 0;
    for (int i = 0; i < sizeof(many)/sizeof(int); i++){
        if (max == many[i]){
            flag += 1;
            locate = i;
        }
    }
    // 만약 flag가 1이면 최대 빈도 알파벳 1개 -> alpha의 locate번째 문자 출력
    // 1보다 크면 최대 빈도 알파벳 2개 이상 -> ?출력
    if (flag > 1){
        printf("?");
    }
    else{
        printf("%c", alpha[locate]);
    }
   
}