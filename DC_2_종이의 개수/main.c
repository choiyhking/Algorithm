// BOJ_1780

#define _CRT_SECURE_NO_WARNINGS

#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>

void divideMat(int n, int start_row, int start_col);
void printRes();

// for convenience
int** mat;
int cnt_1 = 0, cnt_2 = 0, cnt_3 = 0; // counter of -1, 0, 1

int main() {
	int n, temp;

	/*
	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("File open error!\n");
		exit(1);
	}

	fscanf(fp, "%d", &n);
	*/

	scanf("%d", &n);

	mat = (int**)malloc(sizeof(int*) * n);
	for (int i = 0;i < n;i++) {
		mat[i] = (int*)malloc(sizeof(int) * n);
	}
	
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			//fscanf(fp, "%d", &temp);
			scanf("%d", &temp);
			mat[i][j] = temp;
		}
	}

	divideMat(n, 0, 0);

	printRes();

	free(mat);

	return 0;
}

void count(int flag) {
	switch (flag) {
	case -1:
		cnt_1++;
		break;
	case 0:
		cnt_2++;
		break;
	case 1:
		cnt_3++;
		break;
	}
}

int check(int n, int s_row, int s_col) { // n by n matrix
	int temp = mat[s_row][s_col];

	for (int i = s_row;i < s_row + n;i++) {
		for (int j = s_col;j < s_col + n;j++) {
			if (temp != mat[i][j]) return FALSE;
		}
	}
	count(temp); // all number is same!

	return TRUE;
}

void divideMat(int n, int start_row, int start_col) {
	int res = check(n, start_row, start_col);
	if ( n > 1 && res == FALSE) { // exit condition!
		for (int i = start_row;i < start_row + n;i += n / 3) { // divide to 9 matrices
			for (int j = start_col;j < start_col + n;j += n / 3){
				divideMat(n / 3, i, j);
			}
		}
	}
}

void printRes() {
	printf("%d\n", cnt_1);
	printf("%d\n", cnt_2);
	printf("%d\n", cnt_3);
}