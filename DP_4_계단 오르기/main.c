// BOJ_2579

#define _CRT_SECURE_NO_WARNINGS
#define maximum(a,b) ((a>b)?a:b)

#include <stdio.h>
#include <stdlib.h>

int* S, * stairs;
int n;

int calMax();

int main() {
	scanf("%d", &n);
	S = (int*)malloc(sizeof(int) * (n + 1));
	stairs = (int*)malloc(sizeof(int) * (n + 1));

	// init
	for (int i = 1;i <= n;i++) {
		scanf("%d", &stairs[i]);
	}

	S[0] = 0;
	S[1] = stairs[1];
	S[2] = stairs[1] + stairs[2];

	int res = calMax();

	printf("%d", res);

	free(S);
	free(stairs);

	return 0;
}

int calMax() {
	for (int i = 3;i <= n;i++) {
		S[i] = maximum(S[i - 2] + stairs[i], S[i - 3] + stairs[i - 1] + stairs[i]);
	}

	return S[n];
}