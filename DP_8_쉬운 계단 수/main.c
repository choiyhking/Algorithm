// https://www.acmicpc.net/problem/10844

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int	calNum(int n);

int** D;

int main() {
	int n;
	
	scanf("%d", &n);

	D = (int**)malloc(sizeof(int*) * 11);
	for (int i = 0;i <= 10;i++) {
		D[i] = (int*)malloc(sizeof(int) * (n+1));
	}

	// init
	for (int i = 0;i <= 9;i++)
		D[i][1] = 1;

	for (int i = 1;i <= n;i++)
		D[10][i] = 0;

	int res = calNum(n);

	printf("%d", res);

	return 0;
}

int	calNum(int n) {
	int res = 0;

	for (int j = 2;j <= n;j++) {
		D[0][j] = D[1][j - 1] % 1000000000;

		for (int i = 1;i <= 9;i++) {
			D[i][j] = (D[i - 1][j - 1] + D[i + 1][j - 1]) % 1000000000;
		}
	}

	// sum
	for (int i = 1;i <= 9;i++) {
		res += D[i][n];
		res = res % 1000000000;
	}

	return res;
}