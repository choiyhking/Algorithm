// BOJ_11404

#define _CRT_SECURE_NO_WARNINGS
#define INF 99999999

#include <stdio.h>
#include <stdlib.h>

void floyd(int n);
void printD(int n);

int** D;

int main() {
	int n, m; // the number of vertices, edges
	int a, b, c; // start, dest, cost

	/*FILE* fp;
	if ((fp = fopen("input.txt", "r")) == NULL) {
		fprintf("file open error!\n", stderr);
		exit(1);
	}*/

	fscanf(stdin, "%d\n%d", &n, &m);
	D = (int**)malloc(sizeof(int*) * (n + 1)); // we use index 1 ~ n
	for (int i = 0;i < n + 1;i++) {
		D[i] = (int*)malloc(sizeof(int) * (n + 1));
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
	
	/*while (!feof(fp)) {
		fscanf(fp, "%d %d %d", &a, &b, &c);
		
		if(D[a][b] > c) // edge [a, b] can be multiple
			D[a][b] = c;
	}*/

	for (int i = 0;i < m;i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (D[a][b] > c) // edge [a, b] can be multiple
			D[a][b] = c;
	}

	floyd(n);
	printD(n);

	free(D);

	return 0;
}

void floyd(int n) {
	for (int k = 1;k <= n;k++) {
		for (int i = 1;i < n + 1;i++) {
			for (int j = 1;j < n + 1;j++) {
				if (D[i][j] > D[i][k] + D[k][j])
					D[i][j] = D[i][k] + D[k][j];
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