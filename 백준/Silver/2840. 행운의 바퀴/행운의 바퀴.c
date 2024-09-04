#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//노드 선언
typedef struct tagNode {
    char alpha;
    int index;
    struct tagNode* PreNode;
    struct tagNode* NextNode;
} Node;

//노드 생성
Node* CreateNode(char new_alpha) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->alpha = new_alpha;
    NewNode->index = 0;
    NewNode->PreNode = NULL;
    NewNode->NextNode = NULL;

    return NewNode;
}

//노드 지우기
void destroyNode(Node* Current) {
    free(Current);
}

//노드 추가
void AppendNode(Node** Head, Node* NewNode) {
    if ((*Head) == NULL) {
        (*Head) = NewNode;
        (*Head)->NextNode = *Head;
        (*Head)->PreNode = *Head;
    }
    else {
        Node* Tail = (*Head)->PreNode;
        Tail->NextNode = NewNode;
        NewNode->PreNode = Tail;
        NewNode->NextNode = *Head;
        (*Head)->PreNode = NewNode;
    }
}

//노드 검색
Node* SearchNode(Node** Head, int steps) {
    Node* Current = *Head;
    while (steps > 0) {
        Current = Current->NextNode;
        steps--;
    }
    return Current;
}

//노드 역순으로 출력
void printReverseNode(Node* Head, int num) {
    Node* Current = Head;
    while (num > 0) {
        printf("%c", Current->alpha);
        Current = Current->PreNode; //역순으로 출력하기 위한 코드
        num--;
    }
    printf("\n");
}

int main() {

    Node* List = NULL;
    Node* Current = NULL;
    int N, M; //N:노드개수, M: 입력 횟수
    scanf("%d %d", &N, &M);
    int N2 = N;
    int M2 = M;

    while (N-- > 0) {
        AppendNode(&List, CreateNode('?')); // "?"로 리스트 초기화
    }
    //printNode(List, N2);
    int total = 0; // 입력된 count 값의 총 합계 계산을 위한 변수
    int count; // 글자가 바뀐 횟수
    int flag = 0; // 행운의 바퀴인지 아닌지를 판단하기 위한 플래그
    char word; // 회전을 멈췄을 때 가리킨 글자 입력 받기 위한 변수
   
    int used_words[26] = { 0 };

    while (M > 0) {
        scanf("%d %c", &count, &word);
        total += count;
        Current = SearchNode(&List, total);
        
        if ((Current->alpha == word)) { //현재 노드의 글자와 변경될 글자가 같을 때
            flag = 0; //플래그는 0으로 유지
        }
        else if ((Current->alpha == '?') && (!used_words[word - 'A'])){
            Current->alpha = word; //현재 노드의 글자를 새로운 글자로 변경
            used_words[word - 'A'] = 1; // word가 B라면 used_word[1] = 1(참), 1이면 사용한 글자, 0이면 사용안한 글자.
            Current->index = total % N2; //현재 노드의 인덱스는 total 나누기 노드 개수의 나머지
            flag = 0;
        }
        else {
            flag = 1; //플래그 변경
            break;
        }
        M--;
    }
    if (flag == 0) { // flag가 0이거나 중복이 없으면
        printReverseNode(Current, N2);
    }
    else {
        printf("!\n");
    }
    
    return 0;
}
// 행운의 바퀴가 아닌 경우 !이 출력되게 수정할 것..!! -> 수정 완료!!!!!!!!