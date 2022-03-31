// https://www.acmicpc.net/problem/2315

#define _CRT_SECURE_NO_WARNINGS
#define MAX 0x7fffffff
//#define min(a,b) ((a<b) ? a : b)

#include <stdio.h>
#include <stdlib.h>

int calMinSum(int left, int right, int where);

int n, m;
int location[1001], value[1001], c_sum[1001]; // c_sum is cumulative sum
int dp[1001][1001][2];

int main() {
	scanf("%d %d", &n, &m);
	
	for (int i = 1;i <= n;i++) {
		scanf("%d %d", &location[i], &value[i]);
		c_sum[i] = c_sum[i - 1] + value[i];
	}

	// init
	for (int i = 0;i <= 1000;i++) {
		for (int j = 0;j <= 1000;j++) {
			for (int k = 0;k < 2;k++) {
				dp[i][j][k] = -1;
			}
		}
	}

	int res = calMinSum(m, m, 0);
	printf("%d", res);

	return 0;
}

int calMinSum(int left, int right, int where) {
	if (left == 1 && right == n) { // finished(no more consumption = all lights are off)
		return 0;
	} 

	if (dp[left][right][where] != -1) {
		return dp[left][right][where];
	}

	int res = MAX;
	int now = where ? right : left;
	
	// choose the next path with the smallest cost!!(left or right)
	if (left - 1 >= 1) { // go left until #1 light(leftmost)
		res = calMinSum(left - 1, right, 0) + (location[now] - location[left - 1]) * (c_sum[n] - c_sum[right] + c_sum[left - 1]);
		// calMinSum(left - 1, right, 0) + all costs of lights still turned on when going from left to left-1
	}
	if (right + 1 <= n) { // go right until #n light(rightmost)
		res = min(res, calMinSum(left, right + 1, 1) + (location[right + 1] - location[now]) * (c_sum[n] - c_sum[right] + c_sum[left - 1]));
		// min(cost when going left, cost when going right) 
	}

	dp[left][right][where] = res;

	return res;
}