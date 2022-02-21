// BOJ_14600
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	int k, x, y;

	scanf("%d", &k);
	getc(stdin); // '\n'
	scanf("%d %d", &x, &y);

	int len = (int)pow(2, k);

	square = (int**)malloc(sizeof(int*) * len);
	for (int i = 0;i < len;i++) {
		square[i] = (int*)malloc(sizeof(int) * len);
	}

	square[len - y][x - 1] = -1;

	Pos init_pos = { len - y, x - 1 };
	Pos init_ori = { len / 2, len / 2 };

	fill(len, init_ori, init_pos);
	printSquare(len);

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
				continue;  // selected quadrant is already filled or has '-1'
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

				// consider as '-1' in each quadrant
				if (t != flag) {
					next_pos.x += i; next_pos.y += j;
				}
				else next_pos = pos;

				fill(n / 2, next_ori, next_pos);
			}
		}
	}
}

void printSquare(int n) {
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			printf("%d ", square[i][j]);
		}
		printf("\n");
	}
}