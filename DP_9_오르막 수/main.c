// https://www.acmicpc.net/problem/11057

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int** dp;

int calNum(int n);

int main() {
	int n;

	scanf("%d", &n);

	dp = (int**)malloc(sizeof(int*) * 10);
	for (int i = 0;i <= 9;i++) {
		dp[i] = (int*)malloc(sizeof(int) * n);
	}

	// init
	for (int i = 0;i <= 9;i++) {
		dp[i][0] = 1;
	}

	printf("%d", calNum(n));

	free(dp);

	return 0;
}

int calNum(int n) {
	int res = 10; // N = 1

	for (int j = 1;j < n;j++) { // col
		dp[0][j] = res;
		
		for (int i = 1;i <= 9;i++) { // row
			dp[i][j] = (dp[i-1][j] - dp[i - 1][j - 1] + 10007) % 10007;
			res += dp[i][j];
			res %= 10007;
		}
	}

	return res;
}