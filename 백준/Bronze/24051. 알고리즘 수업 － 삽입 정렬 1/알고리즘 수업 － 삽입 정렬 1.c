#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int length, int K) {
	int i, j, key;
	int count = 0;

	for (i = 1; i < length; i++) {
		key = arr[i];
		for (j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
			//printf("%d", arr[j]);
			count++;
			if (count == K) {
				printf("%d", arr[j + 1]);
				break;
			}
		}
		if (arr[j + 1] != key) {
			//printf("%d", key);
			count++;
			arr[j + 1] = key;
		}
		arr[j + 1] = key;

	}
	if (count < K) {
		printf("%d", -1);
	}
}
int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);

	int* arr = (int*)malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	insertionSort(arr, N, K);
	/*
	for (int i = 0; i < K; i++) {
		printf("%d", arr[i]);
	}
	*/
}