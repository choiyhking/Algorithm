// BOJ_11780

#define _CRT_SECURE_NO_WARNINGS
#define INF 99999999
#define MAX 100

#include <stdio.h>
#include <stdlib.h>

void floyd(int n);
void printD(int n);
void savePath(int i, int j);

int** D;
int** P;
int path[MAX];
int idx = 0;

int main() {
	int n, m; // the number of vertices, edges
	int a, b, c; // start, dest, cost

	fscanf(stdin, "%d\n%d", &n, &m);
	
	D = (int**)malloc(sizeof(int*) * (n + 1)); // we use index 1 ~ n
	for (int i = 0;i < n + 1;i++) {
		D[i] = (int*)malloc(sizeof(int) * (n + 1));
	}

	P = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0;i < n + 1;i++) {
		P[i] = (int*)malloc(sizeof(int) * (n + 1));
	}

	// init
	for (int i = 1;i < n + 1;i++) {
		for (int j = 1;j < n + 1;j++) {
			if (i == j)
				D[i][j] = 0;
			else
				D[i][j] = INF;
		}
	}

	for (int i = 1;i < n + 1;i++) {
		for (int j = 1;j < n + 1;j++) {
			P[i][j] = 0;
		}
	}

	for (int i = 0;i < m;i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (D[a][b] > c) // edge [a, b] can be multiple
			D[a][b] = c;
	}

	floyd(n);
	printD(n);

	for (int i = 1;i < n + 1;i++) {
		for (int j = 1;j < n + 1;j++, idx = 0) {
			if (D[i][j] == 0 || D[i][j] == INF) {
				printf("0\n");
			}
			else {
				path[idx++] = i;
				savePath(i, j);
				path[idx] = j;

				printf("%d ", idx + 1);
				for (int x = 0;x <= idx;x++)
					printf("%d ", path[x]);
				printf("\n");
			}
		}
	}

	free(D);
	free(P);

	return 0;
}

void floyd(int n) {
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i < n + 1;i++) {
			for (int j = 1;j < n + 1;j++) {
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k; // save path
				}
			}
		}
	}
}

void printD(int n) {
	for (int i = 1;i < n + 1;i++) {
		for (int j = 1;j < n + 1;j++) {
			if (D[i][j] == INF)
				printf("%d ", 0);
			else printf("%d ", D[i][j]);
		}
		printf("\n");
	}
}

void savePath(int i, int j) {
	if (P[i][j] != 0) {
		savePath(i, P[i][j]);
		path[idx++] = P[i][j];
		savePath(P[i][j], j);
	}
}