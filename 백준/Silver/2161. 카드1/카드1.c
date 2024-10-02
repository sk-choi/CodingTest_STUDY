#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int data;
} Node;

typedef struct tagQueue{
    int Front;
    int Rear;
    int capacity;
    Node* Nodes;
} CCLQueue;

void createQueue(CCLQueue** Queue, int capacity){
    (*Queue) = (CCLQueue*)malloc(sizeof(CCLQueue));
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
    (*Queue)->capacity = capacity;
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(capacity+1));
}

void Enqueue(CCLQueue* Queue, int newdata){
    int position = 0;
    if (Queue->Rear == Queue->capacity){
        position = Queue->Rear;
        Queue->Rear = 0;
    }
    else{
        position = Queue->Rear++;
    }
    Queue->Nodes[position].data = newdata;
}

int Dequeue(CCLQueue* Queue){
    int position = Queue->Front;
    if (Queue->Front == Queue->capacity){
        Queue->Front = 0;
    }
    else{
        Queue->Front++;
    }
    return Queue->Nodes[position].data;
}

int size(CCLQueue* Queue){
    int a = Queue->Front;
    int b = Queue->Rear;
    int c = Queue->capacity;
    return (b - a + c) % c;
}

int main(void){
    
    CCLQueue* Queue = NULL;
    
    int N;
    scanf("%d", &N);
    
    createQueue(&Queue, N);
    
    for (int i = 0; i < N; i++){
        Enqueue(Queue, i+1);
    }
    
    int output;
    
    for (int j = 0; j < N; j++){
        output = Dequeue(Queue);
        Enqueue(Queue, Dequeue(Queue));
        printf("%d ", output);
    }
}





