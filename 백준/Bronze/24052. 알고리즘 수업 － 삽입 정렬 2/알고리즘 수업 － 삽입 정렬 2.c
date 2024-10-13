#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
void  insertion_sort(int A[], int N, int K)
{
	int cnt = 0;
	int num = 0;
	for (int i = 1; i < N; i++)
	{
		int j = i - 1;
		int save = A[i];
		while (j >= 0 && save < A[j])
		{
			A[j + 1] = A[j];
			cnt++;
			if (cnt == K) {
				//num = A[j + 1];
				for (int k = 0; k < N; k++)
		        {
			        printf("%d ", A[k]);
		        }
				break;
			}
			j--;
		}
		if (j + 1 != i)
		{
			A[j + 1] = save;
			cnt++;
		}
		
	}
	if (K > cnt) {
		printf("-1\n");
	}
}
int main()
{
	int N, K, a, b;
	int A[10000];
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);
	}
	insertion_sort(A, N, K);
	
	return 0;
}