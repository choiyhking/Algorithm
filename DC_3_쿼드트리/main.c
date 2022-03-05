// BOJ_1992

#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

int check(int n, int start_i, int start_j);
void divideMat(int n, int start_i, int start_j);

int** mat;

int main() {
	/*FILE* fp;
	if ((fp = fopen("input.txt", "r")) == NULL) {
		fprintf("file open error!\n", stderr);
		exit(1);
	}*/

	int n;
	
	fscanf(stdin, "%d", &n);

	mat = (int**)malloc(sizeof(int*) * n);
	for (int i = 0;i < n;i++) {
		mat[i] = (int*)malloc(sizeof(int) * n);
	}
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			fscanf(stdin, "%1d", &mat[i][j]); // get one digit
		}
	}

	divideMat(n, 0, 0);

	return 0;
}

int check(int n, int start_i, int start_j) {
	int pivot = mat[start_i][start_j];

	for (int i = start_i;i < start_i + n;i++) {
		for (int j = start_j;j < start_j + n;j++) {
			if (mat[i][j] != pivot)
				return FALSE;
		}
	}
	printf("%d", pivot);
	return TRUE;
}

void divideMat(int n, int start_i, int start_j) {
	int res = check(n, start_i, start_j);
	int next_size = n / 2;

	if (res == FALSE && n >= 2) { // exit condition
		printf("(");
		for (int i = start_i;i < start_i + n;i += next_size) {
			for (int j = start_j;j < start_j + n;j += next_size) {
				divideMat(next_size, i, j);
			}
		}
		printf(")");
	}
}