// BOJ_11049

#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999

#include <stdio.h>
#include <stdlib.h>

int** A;
int* d;
int n;

int minMult();

int main() {
	int t1, t2;

	scanf("%d", &n);
	
	A = (int**)malloc(sizeof(int*) * (n + 1)); // we use 1 ~ n
	for (int i = 0;i <= n;i++) {
		A[i] = (int*)malloc(sizeof(int) * (n + 1));
	}

	d = (int*)malloc(sizeof(int) * (n + 1)); // d0 ~ dn

	for (int idx = 0, i = 0;i < n;i++) {
		scanf("%d %d", &t1, &t2);

		d[idx++] = t1;
		d[idx] = t2;
	}

	// init
	for (int i = 1;i <= n;i++) {
		A[i][i] = 0;
	}

	int res = minMult();

	printf("%d\n", res);

	return 0;
}

int minMult() {
	// valid only when i<=j(upper triangle)

	for (int diagonal = 1;diagonal < n;diagonal++) {
		for (int i = 1;i <= n - diagonal;i++) {
			int j = i + diagonal;
			int min = INF;

			for (int k = i;k < j;k++) {
				int n_mul = A[i][k] + A[k + 1][j] + (d[i-1]*d[k]*d[j]);

				if (min > n_mul) {
					min = n_mul;
				}
			}

			A[i][j] = min;
		}
	}

	return A[1][n];
}