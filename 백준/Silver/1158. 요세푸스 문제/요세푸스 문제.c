#include <stdio.h>
#include <stdlib.h>

// 환형 리스트


// 오답 노트: 환형리스트에서 K번째 노드의 위치를 찾는 SearchNode를 구현할 때 환형리스트에서 탐색을
// 진행할 때는 길이를 고려하면 안된다는 것을 깨달았다. 기존의 탐색 기능은 NULL이 나오면 탐색 반복을 멈추는 코드가 있었다.
// 따라서 steps의 크기 만큼 계속 탐색을 진행하게 바꾸었다.
typedef struct tagNode{
    int data;
    struct tagNode* PreNode;
    struct tagNode* NextNode;
} Node;

Node* CreateNode(int new_data){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = new_data;
    NewNode->PreNode = NULL;
    NewNode->NextNode = NULL;
    
    return NewNode;
}

void Append_Node(Node** Head, Node* NewNode){
    
    if ((*Head) == NULL){
        *Head = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PreNode = *Head;
    }
    else{
        Node* Tail = (*Head)->PreNode;
        
        Tail->NextNode->PreNode = NewNode;
        Tail->NextNode = NewNode;
        
        NewNode->NextNode = (*Head);
        NewNode->PreNode = Tail;
    }
}

void Remove_Node(Node** Head, Node* Remove){
    
    if((*Head) == Remove){
        (*Head)->PreNode->NextNode = Remove->NextNode;
        (*Head)->NextNode->PreNode = Remove->PreNode;
        (*Head) = Remove->NextNode;
        
        Remove->PreNode = NULL;
        Remove->NextNode = NULL;
    }
    else{
        Remove->PreNode->NextNode = Remove->NextNode;
        Remove->NextNode->PreNode = Remove->PreNode;
        
        Remove->PreNode = NULL;
        Remove->NextNode = NULL;
    }
}

Node* SearchNode(Node* Head, int steps){ //노드 탐색: Steps 번째에 있는 노드를 탐색한다. 
    
    Node* Current = Head;
    
    while(steps > 0){
        Current = Current->NextNode;
        steps--;
    }
    return Current;
}

void PrintNode(Node* Head){
    
    Node* Current = Head;
    
    if(Current == NULL){
        printf("There is not node");
    }
    else{
        Node* Start = Current;
        printf("%s", "Circular List printing result:\n");
        do{
          printf("%d", Current->data);
          Current = Current->NextNode;
        } while(Start != Current);
        printf("\n");
    }
}

int CountNode(Node* Head){
    unsigned int count = 0;
    Node* Current = Head;
    
    while(Current != NULL){
        Current = Current->NextNode;
        count++;
        if (Current == Head){
            break;
        }
    }
    return count;
}

// destroy node
void DestroyNode(Node* Node){
    free(Node);
}

int main(void){
    
    int N,K;
    scanf("%d %d", &N, &K);
    
    Node* List = NULL;
    Node* Current = NULL;
    for (int i = 1; i <= N; i++){
        Append_Node(&List, CreateNode(i));
    }

    Current = List;
    printf("%c", '<');
    while(N > 0){
        if(N > 1){
            Current = SearchNode(Current, K - 1);
            printf("%d, ", Current->data); // 노드 데이터 출력
            Node* NextNode = Current->NextNode; 
            Remove_Node(&List, Current); // 현재 노드 지우고
            Current = NextNode; // 현재노드로 다음 노드 지정
        }
        else{
            Current = SearchNode(Current, K - 1);
            printf("%d", Current->data); // 노드 데이터 출력
            Node* NextNode = Current->NextNode; 
            Remove_Node(&List, Current); // 현재 노드 지우고
            Current = NextNode; // 현재노드로 다음 노드 지정
        }
        N--;
    }
    printf("%c", '>');
   
    
}