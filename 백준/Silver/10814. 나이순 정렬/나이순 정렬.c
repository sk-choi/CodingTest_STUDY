#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
    int age;
    char name[101];
    int reg; // 가입한 순서 저장
} Node;

int compare(const Node* a, const Node* b){
    
    if (a->age > b->age){
        return 1;
    }
    else if (a->age < b->age){
        return -1;
    }
    else {
        if (a->reg > b->reg){
            return 1;
        }
        else if (a->reg < b->reg){
            return -1;
        }
        else {
            return 0;
        }
    }
    
}

int main(){
    
    int N;
    scanf("%d", &N);
    Node* Nodes = (Node*)malloc(sizeof(Node) * N);
    
    for (int i = 0; i < N; i++){
        scanf("%d", &Nodes[i].age);
        scanf("%s", Nodes[i].name);
        Nodes[i].reg = i;
        //printf("%d %s\n", Nodes[i].age, Nodes[i].name);
    }
    
    qsort(Nodes, N, sizeof(Node), compare);
    
    for (int i = 0; i < N; i++){
        printf("%d ", Nodes[i].age);
        printf("%s\n", Nodes[i].name);
    }
    
}