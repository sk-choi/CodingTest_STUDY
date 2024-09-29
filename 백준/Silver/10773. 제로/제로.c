#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int data;
} Node;

typedef struct tagStack{
    Node* Nodes;
    int top;
} ArrayStack;

Node* createNode(int data){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = data;
    
    return NewNode;
}

void createStack(ArrayStack** Stack, int capacity){
    (*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
    (*Stack)->Nodes = (Node*)malloc(sizeof(Node)*capacity);
    (*Stack)->top = -1;
}

void push(ArrayStack* Stack, int data){
    int position = Stack->top + 1;
    Stack->Nodes[position].data = data;
    Stack->top++;
}

int pop(ArrayStack* Stack){
    int position = Stack->top;
    Stack->top--;
    return Stack->Nodes[position].data;
}

int isEmpty(ArrayStack* Stack){
    return (Stack->top == -1);
}

int main() {
    
    int K;
    scanf("%d", &K);
    ArrayStack* Stack = NULL;
    createStack(&Stack, K);
    
    for (int i = 0; i < K; i++){
        int input;
        scanf("%d", &input);
        if (input != 0){
            push(Stack, input);
        }
        else{
            pop(Stack);
        }
    }
    
    int sum = 0;
    while(!isEmpty(Stack)){
        int num = pop(Stack);
        sum += num;
    }
    printf("%d", sum);
    
    
}