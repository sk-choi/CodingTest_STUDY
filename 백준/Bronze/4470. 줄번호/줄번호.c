#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int N = 0;
    scanf("%d", &N);
    getchar(); // 정수 입력 시 포함된 공백이 버퍼에 남아 fgets가 읽어서 word[0]에 공백 들어갈 수 있어서 모든 공백 제거.
    
    char** word = (char**)malloc(sizeof(char*) * (N+1)); // 이중 포인터로 문자열이 각각 저장되는 이중 배열 메모리 할당
    
    for (int i = 0; i < N; i++){
        
        char arr[52] = {0,}; 
        
        fgets(arr, sizeof(arr), stdin); //arr 배열에 값 입력
        arr[strcspn(arr,"\n")] = '\0';
        
        word[i] = (char*)malloc(sizeof(char) * strlen(arr)+1);
        
        strcpy(word[i], arr); // arr에 입력된 값을 word[i]에 할당
    }
    
    for (int i = 0; i < N; i++){
        if (i < N-1){
            printf("%d. %s\n", i+1, word[i]);
        }
        else{
            printf("%d. %s", i+1, word[i]);
        }
    }
    
    
    for (int i = 0; i < N; i++) {
        free(word[i]);
    }
    free(word);
    return 0;
}

//출력 마지막에 공백이 포함되어야 한다.
//그래서 입력 받은 값에서 개행 문자를 제거하고, 출력할 때 공백 포함하고 개행문자를 넣고 출력