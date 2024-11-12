#include <stdio.h>
#define SIZE 21

//add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
//remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
//check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
//toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
//all: S를 {1, 2, ..., 20} 으로 바꾼다.
//empty: S를 공집합으로 바꾼다.

void add(int s[], int x){
    
    if (s[x] == 0){
        s[x] = 1;
    }
    else{
        return;
    }
}

void removel(int s[], int x){
    
    if (s[x] == 1){
        s[x] = 0;
    }
    else{
        return;
    }
}

void check(int s[], int x){
    
    if (s[x] == 1){
        printf("%d\n", 1);
    }
    else{
        printf("%d\n", 0);
    }
}

void toggle(int s[], int x){
 
    if (s[x] == 1){
        s[x] = 0;
    }
    else{
        s[x] = 1;
    }
}

void all(int s[]){
    for (int i = 1; i < SIZE; i++){
        s[i] = 1;
    }
}

void empty(int s[]){
    
    for (int i = 1; i < SIZE; i++){
        s[i] = 0;
    }
}

int main(void){
    
    int s[SIZE] = {0,};
    
    int N;
    scanf("%d", &N);
    
    char option[10] = {};
    for (int i = 0; i < N; i++){
        scanf("%s", &option);
        
        int num;
        if (strcmp(option, "add") == 0){
            scanf("%d", &num);
            add(s, num);
        }
        
        else if (strcmp(option, "remove") == 0){
            scanf("%d", &num);
            removel(s, num);
        }
        
        else if (strcmp(option, "check") == 0){
            scanf("%d", &num);
            check(s, num);
        }
        
        else if (strcmp(option, "toggle") == 0){
            scanf("%d", &num);
            toggle(s, num);
        }
        
        else if (strcmp(option, "all") == 0){
            scanf("%d", &num);
            all(s);
        }
        else{
            empty(s);
        }
    }
}