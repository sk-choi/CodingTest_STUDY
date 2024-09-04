#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int N, M; //수의 개수: N, 합을 구해야 하는 횟수: M
	scanf("%d %d", &N, &M);

	//int cumulative_sum[N + 1] = {};
	int* cumulative_sum = (int*)malloc((N + 1) * sizeof(int));
	cumulative_sum[0] = 0;

	for (int i = 0; i < N; i++) {
		int input;
		int sum = 0;
		scanf("%d", &input);
		cumulative_sum[i+1] = cumulative_sum[i] + input;
	}

	//int start, end; 여긴 합을 구하는 부분
	for (int j = 0; j < M; j++) {
		int start, end;
		scanf("%d %d", &start, &end);
        int total_sum = cumulative_sum[end] - cumulative_sum[start-1];
		printf("%d\n", total_sum);
	}
    return 0;
}
// 기존 합의 결과를 다시 재활용할 수 있을까?????
// 누적합의 범위가 새롭게 입력될 때마다 다시 반복문을 돌려야하는 단점 발생.

// --> 따로 누적합을 저장해 놓은 배열을 만들면 빠르게 답을 구할 수 있다!!

