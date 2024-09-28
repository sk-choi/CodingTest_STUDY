#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagNode {
    int data;
} Node;

typedef struct tagQueue {
    int capacity;
    int Front;
    int Rear;
    Node* Nodes;
} CircularQueue;

void createQueue(CircularQueue** Queue, int capacity) {
    (*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
    (*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (capacity + 1));
    (*Queue)->capacity = capacity;
    (*Queue)->Front = 0;
    (*Queue)->Rear = 0;
}

void push(CircularQueue* Queue, int data) {
    int position = 0;

    if (Queue->Rear == Queue->capacity) {
        position = Queue->Rear; //맨 마지막 노드의 위치에 넣어야함 Rear는 맨 마지막 노드 다음에 위치함.
        Queue->Rear = 0;
    }
    else
        position = Queue->Rear++;

    Queue->Nodes[position].data = data;
}

int pop(CircularQueue* Queue) {
    int position = Queue->Front;
    
    if (isEmpty(Queue)){
        return -1;
    }
    else if (Queue->Front == Queue->capacity) {
        Queue->Front = 0;
    }
    else
        Queue->Front++;

    return Queue->Nodes[position].data;
}

int front(CircularQueue* Queue) {
    int position = Queue->Front;
    if (isEmpty(Queue) == 1){
        return -1;
    }
    else{
        return Queue->Nodes[position].data;
    }
}

int rear(CircularQueue* Queue) {

    int position = 0;
    if (isEmpty(Queue)){
        return -1;
    }
    else if (Queue->Rear != 0){
        position = Queue->Rear - 1;
    }
    else{
        position = Queue->capacity - 1;
    }
    return Queue->Nodes[position].data;
}

int isEmpty(CircularQueue* Queue) {

    return (Queue->Front == Queue->Rear);
}

int size(CircularQueue* Queue) {

    if (Queue->Front <= Queue->Rear) {
        return Queue->Rear - Queue->Front;
    }
    else
        return Queue->Rear + (Queue->capacity - Queue->Front) + 1;
}

int main(void) {

    CircularQueue* Queue = NULL;

    int N;
    scanf("%d", &N);
    createQueue(&Queue, N);
    
    char option[10];
    for (int i = 0; i < N; i++) {
        int input;
        scanf("%s ", option);
        if (strcmp(option,"push") == 0) {
            scanf("%d", &input);
            push(Queue, input);
        }
        else if (strcmp(option, "pop") == 0) {
            printf("%d\n", pop(Queue));
        }
        else if (strcmp(option, "front") == 0) {
            printf("%d\n", front(Queue));
        }
        else if (strcmp(option, "back") == 0) {
            printf("%d\n", rear(Queue));
        }
        else if (strcmp(option, "size") == 0) {
            printf("%d\n", size(Queue));
        }
        else if (strcmp(option, "empty") == 0) {
            printf("%d\n", isEmpty(Queue));
        }
    }

}

