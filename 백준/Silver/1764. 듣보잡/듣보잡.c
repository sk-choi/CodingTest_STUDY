#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct string{
    char word[21];
} String;

//return strcmp(a->word, b->word);
int string_compare(const String* a, const String* b){
    
    return strcmp(a->word, b->word); // a가 b보다 크면 양수, 반대면 음수, 같으면 0;
}

int main(void){
    
    int N, M;
    
    scanf("%d", &N);
    scanf("%d", &M);
    
    String* arr = (String*)malloc(sizeof(String)*(N+M));
    
    for (int i = 0; i < N+M; i++){
        scanf("%s", &arr[i].word);
    }
    
    qsort(arr, N+M, sizeof(String), string_compare);
    
    int count = 0;
    for (int i = 0; i < N+M-1; i++){
        if (strcmp(arr[i].word, arr[i+1].word) == 0){
            count++;
        }
    }
    
    printf("%d\n", count);
    
    for (int i = 0; i < N+M-1; i++){
        if (strcmp(arr[i].word, arr[i+1].word) == 0){
            printf("%s\n", arr[i].word);
        }
    }
    
}