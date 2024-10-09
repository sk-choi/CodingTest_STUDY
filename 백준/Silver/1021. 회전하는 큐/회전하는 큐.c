#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int data;
    struct tagNode* prenode;
    struct tagNode* nextnode;
} Node;

Node* createNode(int data);
void destroyNode(Node* _Node);
void AppendNode(Node** Head, Node* NewNode);
void RemoveNode(Node** Head, Node* remove);
int moveleft(Node** Head, Node* findNode);
int moveright(Node** Head, Node* findNode);
Node* findNode(Node** Head, int data);
void CDL_PrintNode(Node* Head);

// 노드 생성하는 함수
Node* createNode(int data){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = data;
    NewNode->prenode = NULL;
    NewNode->nextnode = NULL;
    
    return NewNode;
}

void destroyNode(Node* _Node){
    free(_Node);
}

//새 노드를 끝에 추가하는 함수
void AppendNode(Node** Head, Node* NewNode){
    if ((*Head) == NULL){
        (*Head) = NewNode;
        NewNode->prenode = (*Head);
        NewNode->nextnode = (*Head);
    }
    else{
        Node* Tail = (*Head)->prenode; // Tail = 마지막 노드
        Tail->nextnode->prenode = NewNode; 
        // 왜 (*Head)->prenode = NewNode가 안될까? 이미 Tail로 선언을 해서 아마 Current = (*Head)면 가능할지도?? -> 안된다!!!
        Tail->nextnode = NewNode;
        NewNode->nextnode = (*Head);
        NewNode->prenode = Tail;
    }
}

//노드를 제거하는 함수
void RemoveNode(Node** Head, Node* remove){
    
    if ((*Head) == remove){
        if (remove->nextnode == remove){
            (*Head) = NULL;
        }
        else{
            (*Head)->prenode->nextnode = remove->nextnode;
            (*Head)->nextnode->prenode = remove->prenode;
            (*Head) = remove->nextnode;
        }
    }
    else{
        remove->nextnode->prenode = remove->prenode;
        remove->prenode->nextnode = remove->nextnode;
    }
    remove->prenode = NULL;
    remove->nextnode = NULL;
}

//헤드를 왼쪽으로 옮긴 횟수를 리턴하는 함수
int moveleft(Node** Head, Node* findNode){
    int count = 0;
    Node* Current = (*Head);
    
    Node* Start = (*Head);
    do{
        if (Current->data == findNode->data){
            break;
        }
        else{
                Current = Current->prenode;
                count += 1;
        }
    }while(Current != Start);
    
    return count;
}

//헤드를 오른쪽으로 옮긴 횟수를 리턴하는 함수
int moveright(Node** Head, Node* findNode){
    int count = 0;
    Node* Current = (*Head);

    Node* Start = (*Head);
    do{
        if (Current->data == findNode->data){
            break;
        }
        else{
            Current = Current->nextnode;
            count += 1;
        }
    }while(Current != Start);
    
    return count;
}

//찾는 데이터를 가진 노드의 주소를 반환하는 함수
Node* findNode(Node** Head, int data){
    if ((*Head) == NULL){
        return NULL;
    }
    else{
        Node* Current = (*Head);
        Node* Start = (*Head);
        do{
            if(Current->data == data){
                //(*Head) = Current->nextnode;
                return Current;
            }
            else
                Current = Current->nextnode;
        }while(Current != Start);
        //(*Head) = Current->nextnode;
        return NULL;
    }
}

int main(){
    
    Node* List = NULL;
    
    int total_move = 0;
    int N, M; //N : 큐의 크기, M : 뽑을 수의 개수
    scanf("%d %d", &N, &M);
    int* arr = (int*)malloc(sizeof(int) * M);
    
    for (int i = 0; i < N; i++){
        AppendNode(&List, createNode(i+1));
    }
    
    for (int j = 0; j < M; j++){
        scanf("%d", &arr[j]);
    }
    
    int memory = arr[0];
    
    for (int k = 0; k < M; k++){
        int plus = 0;
        int target = arr[k];
        Node* foundNode = findNode(&List, target);
        int left = moveleft(&List, foundNode);
        int right = moveright(&List, foundNode);
        
        List = foundNode;
        
        // 처음에 1씩 움직이는 거면 카운트를 할 필요 없다고 생각해서
        // if(abs(target-memory) != 0)을 조건으로 plus에 더해지는 값을 차이가 있게 했다.
        // 근데 생각해보니 어차피 숫자가 하나씩 출력될 때마다 헤드는 자동으로 다음노드로 넘어가기 때문에
        // 이 조건을 설정할 필요가 없다는 것을 깨달았다!!!!!!!!!!!!
        
        if (left >= right){
            plus = right;
        }
        else{
            plus = left;
        }    
        
        if (foundNode == List){
            List = List->nextnode;
        }

        RemoveNode(&List, foundNode);
        destroyNode(foundNode);
        
        memory = target;
        total_move += plus;
    }
    
    printf("%d", total_move);
}