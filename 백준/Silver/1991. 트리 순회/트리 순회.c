#include <stdio.h>
#include <stdlib.h>

typedef struct tagBTNode
{
    struct tagBTNode* left;
    struct tagBTNode* right;
    
    char data;
}BTNode;

BTNode* createNode(char newdata){
        
    BTNode* NewNode = (BTNode*)malloc(sizeof(BTNode));
    NewNode->left = NULL;
    NewNode->right = NULL;
    NewNode->data = newdata;
    
    return NewNode;
}

/* 원래 내가 작성한 함수:
BTNode* findNode(BTNode* Root, char finddata){
    
    if (Root->data == finddata){
        return Root;
    }
    else{
        return NULL;
    }
    findNode(Root->left, finddata);
    findNode(Root->right, finddata);
}
*/

// 새로 작성한 findNode 함수
BTNode* findNode(BTNode* Root, char finddata){ //findNode 함수의 논리적 오류 때문에 다시 수정!!
    
    if (Root == NULL){
        return NULL;
    }
    
    if (Root->data == finddata){
        return Root;
    }
    BTNode* foundNode = findNode(Root->left, finddata);
    if (foundNode == NULL){
        foundNode = findNode(Root->right, finddata);
    }
    return foundNode;
}

void destroyNode(BTNode* Node){
    free(Node);
}

/*원래 작성했던 addchild함수
void addchild(BTNode* Node, BTNode* Child) {
    if (Node->left == NULL) {
        Node->left = Child;
    }
    else {
        Node->right = Child;
    }
}
*/

void printpreorder(BTNode* Node){
    if (Node == NULL){
        return;
    }
        printf("%c", Node->data);
        printpreorder(Node->left);
        printpreorder(Node->right);
}

void printinorder(BTNode* Node){
    if (Node == NULL){
        return;
    }
    printinorder(Node->left);
    printf("%c", Node->data);
    printinorder(Node->right);
}

void printpostorder(BTNode* Node){
     if (Node == NULL){
        return;
    }
    printpostorder(Node->left);
    printpostorder(Node->right);
    printf("%c", Node->data);
    
}

void destroyTree(BTNode* Node){
    
    if (Node == NULL){
        return;
    }
    destroyTree(Node->left);
    destroyTree(Node->right);
    destroyNode(Node);
}

// 처음에 addchild함수로 left가 없으면 left, left가 있으면 right에 넣는 방식으로 자식 노드를 추가했지만
// 문제에서 요구하는 건 두 번째로 입력한 원소가 left, 세 번째로 입력한 원소가 right로 들어가는 것이므로
// 코드를 문제의 요구 사항에 맞게 수정했다.
int main(void){
    int N;
    scanf("%d", &N);
    
    BTNode* Node = NULL;

    while(N > 0){
        char a, b, c;
        scanf(" %c %c %c", &a, &b, &c);
        
        if (Node == NULL){
            Node = createNode(a);   
            if(b != '.'){
                BTNode* Node2 = createNode(b);
                Node->left = Node2;
            }                
            if(c != '.'){
                BTNode* Node3 = createNode(c);
                Node->right = Node3;
            }
        }
        else{
            BTNode* Node1 = findNode(Node, a);
            if(Node1 != NULL){
                if (b != '.'){
                    BTNode* Node2 = createNode(b);
                    Node1->left = Node2;
                }
                if (c != '.'){
                    BTNode* Node3 = createNode(c);
                    Node1->right = Node3;
                }
            }
        }
        N--;
    }
    
    printpreorder(Node);
    printf("\n");
    printinorder(Node);
    printf("\n");
    printpostorder(Node);
    
    destroyTree(Node);
}