#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int data;
} Node;

typedef struct tagQueue{
    Node* Nodes;
    int Front;
    int Rear;
    int capacity;
} CircularQueue;

void createQueue(CircularQueue** Queue, int capacity){
    (*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(capacity+1));
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
    (*Queue)->capacity = capacity;
}

void Enqueue(CircularQueue* Queue, int new_data){
    
    int position = 0;
    if (Queue->Rear == Queue->capacity){
        position = Queue->Rear;
        Queue->Rear = 0;
    }
    else{
        position = Queue->Rear++;
    }
    Queue->Nodes[position].data = new_data;
}

int Dequeue(CircularQueue* Queue){
    
    int position = Queue->Front;
    if (Queue->Front == Queue->capacity){
        Queue->Front = 0;
    }
    else{
        Queue->Front++;
    }
    return Queue->Nodes[position].data;
}

int size(CircularQueue* Queue){
    return (Queue->Rear - Queue->Front + Queue->capacity) % Queue->capacity;
}

int main(void){
    
    CircularQueue* Queue = NULL;
    
    int N;
    scanf("%d", &N);
    
    createQueue(&Queue, N);
    
    for (int i = 0; i < N; i++){
        Enqueue(Queue, i+1);
    }
    
    int back = 0;
    for (int j = 0; j < N; j++){
        if ((N == 1) || (N == 2)){
            back = N;
            break;
        }
        if (size(Queue) == 1){
            break;
        }
        Dequeue(Queue);
        back = Dequeue(Queue);
        Enqueue(Queue, back);
    }
    printf("%d", back);
}




