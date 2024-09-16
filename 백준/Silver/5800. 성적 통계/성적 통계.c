#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main() {
    int K;
    int student;

    scanf("%d", &K);

    for (int i = 0; i < K; i++) {
        int count = K - K + i +1;
        scanf("%d", &student);
        int* score = (int*)malloc(sizeof(int) * student);
        // 점수 입력
        for (int i = 0; i < student; i++) {
            scanf("%d", &score[i]);
        }

        //정렬
        for (int i = 0; i < student - 1; i++) {
            for (int j = i + 1; j < student; j++) {
                if (score[j] > score[i]) {
                    int temp = score[j];
                    score[j] = score[i];
                    score[i] = temp;
                }
            }
        }
        int minus = 0;
        for (int i = 0; i < student - 1; i++) {
            if (minus < (score[i] - score[i + 1])) {
                minus = score[i] - score[i + 1];
            }
        }
        printf("Class %d\n", count);
        printf("Max %d, Min %d, Largest gap %d\n", score[0], score[student - 1], minus);
        free(score);
    }
}