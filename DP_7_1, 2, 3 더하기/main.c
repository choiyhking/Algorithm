// https://www.acmicpc.net/problem/9095

#define _CRT_SECURE_NO_WARNINGS
#define MAX 11

#include <stdio.h>

int makeSumOf123(int num);

int D[MAX];

int main() {
	int n, temp;

	scanf("%d", &n);

	// init
	D[0] = 1; D[1] = 1; D[2] = 2;
	
	for (int i = 0;i < n;i++) {
		scanf("%d", &temp);

		printf("%d\n", makeSumOf123(temp));
	}
	
	return 0;
}

int makeSumOf123(int num) {
	for (int i = 3;i <= num;i++) {
		D[i] = D[i - 1] + D[i - 2] + D[i - 3];
	}

	return D[num];
}