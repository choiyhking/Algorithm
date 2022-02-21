#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

typedef struct _pos {
	int x, y;
}POS;
typedef POS Pos;

void fill(int n, Pos ori, Pos pos);
void printSquare(int n);

// for convenience
int** square;
int cnt = 1;

int main() {
	int n; // n by n square
	int x, y; // coordinate of 'X'

	FILE* fp = fopen("input.txt", "r");
	if (fp == NULL) {
		printf("File open error!\n");
		exit(1);
	}

	fscanf(fp, "%d", &n);
	fscanf(fp, "%d %d", &x, &y);

	square = (int**)malloc(sizeof(int*) * n);
	for (int i = 0;i < n;i++) {
		square[i] = (int*)malloc(sizeof(int) * n);
	}

	square[x][y] = -1; // 'X'

	Pos init_pos = { x, y };
	Pos init_ori = { n / 2, n / 2 };

	fill(n, init_ori, init_pos);
	printSquare(n);

	free(square);

	return 0;
}

int DetQuadrant(Pos origin, Pos sel) {
	if (sel.x < origin.x && sel.y < origin.y) return 1;
	else if (sel.x < origin.x && sel.y >= origin.y) return 2;
	else if (sel.x >= origin.x && sel.y < origin.y) return 3;
	else return 4;
}

void makeLTromino(int flag, Pos start) { // for 2 by 2 square
	for (int i = 0, temp = 1;i < 2;i++) {
		for (int j = 0; j < 2;j++, temp++) {
			if (temp == flag) 
				continue;  // selected quadrant is already filled or has 'X'
			square[start.x + i][start.y + j] = cnt;
		}
	}
	cnt++;
}

void fill(int n, Pos ori, Pos pos) {
	Pos temp_pos = { ori.x - 1, ori.y - 1 };
	int q = n / 4, flag = DetQuadrant(ori, pos);

	makeLTromino(flag, temp_pos);

	if (n > 2) { // exit condition
		for (int i = 0, t = 1;i < 2;i++) { // for next 4 squares(n -> n/2)
			for (int j = 0; j < 2;j++, t++) {
				Pos next_ori = ori;
				Pos next_pos = { ori.x - 1, ori.y - 1 };

				// new ori
				if (i == 0) next_ori.x -= q;
				else next_ori.x += q;

				if (j == 0) next_ori.y -= q;
				else next_ori.y += q;
				
				// consider as 'X' in each quadrant
				if (t != flag) {
					next_pos.x += i; next_pos.y += j;
				}
				else next_pos = pos;

				fill(n / 2, next_ori, next_pos);
			}
		}
	}
}

void printSquare(int n) { // n by n
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (square[i][j] == -1)
				printf("  X");
			else printf("%3d", square[i][j]);
		}
		printf("\n");
	}
}