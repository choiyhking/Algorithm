// https://www.acmicpc.net/problem/1463

#define _CRT_SECURE_NO_WARNINGS
#define INF 9999999

#include <stdio.h>
#include <stdlib.h>

int minimum(int a, int b, int c);
void convert(int n, int* n1, int* n2, int* n3);

int main() {
	int n, n1, n2, n3;
	int* M;

	scanf("%d", &n);

	M = (int*)malloc(sizeof(int) * (n + 1));
	// init
	M[0] = INF; M[1] = 0; M[2] = 1; M[3] = 1;

	for (int i = 4;i <= n;i++) {
		convert(i, &n1, &n2, &n3);
		M[i] = minimum(M[n1], M[n2], M[n3]) + 1;
	}

	printf("%d", M[n]);

	free(M);

	return 0;
}

void convert(int n, int* n1, int* n2, int* n3) {
	if (n % 3 == 0) *n1 = n / 3;
	else *n1 = 0;

	if (n % 2 == 0) *n2 = n / 2;
	else *n2 = 0;

	*n3 = n - 1;
}

int minimum(int a, int b, int c) {
	if (a < b && a < c) {
		return a;
	}
	else if (b < c) {
		return b;
	}
	else {
		return c;
	}
}