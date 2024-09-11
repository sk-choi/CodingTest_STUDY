#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int data;
}Node;

typedef struct tagStack {
	int capacity;
	int top;
	Node* Nodes;

}ArrayStack;

createStack(ArrayStack** Stack, int capacity) {

	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * capacity);

	(*Stack)->capacity = capacity;
	(*Stack)->top = -1;
}

void destroyStack(ArrayStack* Stack) {
	free(Stack->Nodes);
	free(Stack);
}

void pushStack(ArrayStack* Stack, int new_data) {
	Stack->top++;
	Stack->Nodes[Stack->top].data = new_data;
}

int popStack(ArrayStack* Stack) {
	
	if (isEmpty(Stack) == 1) {
		return -1;
	}
	else {
		int position = Stack->top--;
		return Stack->Nodes[position].data;
	}
}

int isEmpty(ArrayStack* Stack) {
	if (Stack->top == -1) {
		return 1;
	}
	else
		return 0;
}

int topStack(ArrayStack* Stack) {
	if (isEmpty(Stack) == 1) {
		return -1;
	}
	return Stack->Nodes[Stack->top].data;
}

int getSize(ArrayStack* Stack) {
	return Stack->top + 1;
}

int main(void) {
	
	int N;
	scanf("%d", &N);
	ArrayStack* Stack = NULL;
	createStack(&Stack, N);

	for (int i = 0; i < N; i++) {
		int option;
		scanf("%d", &option);

		if (option == 1) {
			int X;
			scanf("%d", &X);
			pushStack(Stack, X);
		}
		else if (option == 2) {
			printf("%d\n", popStack(Stack));
		}
		else if (option == 3) {
			printf("%d\n", getSize(Stack));
		}
		else if (option == 4) {
			printf("%d\n", isEmpty(Stack));
		}
		else {
			printf("%d\n", topStack(Stack));
		}
	}
}