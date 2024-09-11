#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void) {
	char arr[1001];
	int N;
	scanf("%s\n", arr);
	scanf("%d", &N);

	printf("%c", arr[N - 1]);



}