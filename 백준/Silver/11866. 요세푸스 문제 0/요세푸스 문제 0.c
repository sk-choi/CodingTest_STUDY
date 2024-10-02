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

int main(void){
    
    int N, K;
    scanf("%d %d", &N, &K);
    CircularQueue* Queue = NULL;
    createQueue(&Queue, N);
    
    for (int i = 0; i < N; i++){
        Enqueue(Queue, i+1);
    }
    
    int order = 0;
    
    int* arr = (int*)malloc(sizeof(int)*N);
    
    printf("<");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < K; j++){
            if (j == K-1){
                order = Dequeue(Queue);
                arr[i] = order;
                printf("%d", arr[i]);
            }
            else {
                Enqueue(Queue, Dequeue(Queue));
            }
        }
        if (i < N-1){
            printf(", ");
        }
    }
    printf(">");
}




