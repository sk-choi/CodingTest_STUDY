#include <stdio.h>
#include <stdlib.h>

typedef struct tagnode{
    
    struct tagnode* left;
    struct tagnode* right;
    
    int data;
} Node;

Node* createNode(int newdata){
    Node* newnode = (Node*)malloc(sizeof(Node));
    
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = newdata;
    
    return newnode;
}

void makeTree(Node* Tree, Node* Child){
    
    if (Tree->data == Child->data){
        return;
    }
    
    else if (Child->data < Tree->data){
        if (Tree->left != NULL){
            makeTree(Tree->left, Child);
        }
        else{
            Tree->left = Child;
        }
    }
    else if (Child->data > Tree->data){
        if (Tree->right != NULL){
            makeTree(Tree->right, Child);
        }
        else{
            Tree->right = Child;
        }
    }
}

void printInOrder(Node* Tree){
    if (Tree == NULL){
        return;
    }
    printInOrder(Tree->left);
    printf("%d ", Tree->data);
    printInOrder(Tree->right);
    
}

int main(void){
    
    int N;
    scanf("%d", &N);
    
    Node* Tree = NULL;
    
    for (int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);
        
        if (i == 0){
            Tree = createNode(num);
        }
        else{
            Node* Child = createNode(num);
            makeTree(Tree, Child);
        }
    }
    
    printInOrder(Tree);
    
    
}