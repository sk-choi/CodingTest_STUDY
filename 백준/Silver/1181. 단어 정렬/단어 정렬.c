#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode{
    char word[51];
} Node;

int compare(const void* a, const void* b){ // 길이가 짧은 것부터, 길이가 같으면 사전 순으로, 단, 중복된 단어는 하나만 남기고 제거해야 한다.
    
    Node* aa = (Node*)a;
    Node* bb = (Node*)b;
    
    if (strlen(aa) > strlen(bb)){
        return 1;
    }
    else if (strlen(aa) < strlen(bb)){
        return -1;
    }
    else {
        return strcmp(aa->word, bb->word);
    }
}


int main(){
    
    int N;
    scanf("%d", &N);
    
    Node* Nodes = (Node*)malloc(sizeof(Node) * N);
    
    char input[51] = {};
    for(int i = 0; i < N; i++){
        
        char input[51] = {};
        scanf("%s\n", input);
        
        strcpy(Nodes[i].word, input);
    }
    
    qsort(Nodes, N, sizeof(Node), compare);
    
    for (int i = 0; i < N; i++){
        if (i > 0){
            if(strcmp(Nodes[i-1].word, Nodes[i].word) == 0){
                continue;
            }
        }
        printf("%s\n", Nodes[i].word);
    }
    
    //printf("%d", strcmp(arr2, arr1)); //더 앞선 글자가 앞에 있으면 -1 아니면 1 같으면  0
}