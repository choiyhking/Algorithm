// https://www.acmicpc.net/problem/9251

#define _CRT_SECURE_NO_WARNINGS
#define maximum(a, b) ((a>=b) ? a : b)
#define MAX 1002 // worst case: 1000 characters + '\n' + '\0'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s1[MAX], s2[MAX];
int** LCS;

void calLCS();

int main() {
	fgets(s1, MAX, stdin);
	s1[strlen(s1) - 1] = '\0';
	fgets(s2, MAX, stdin);

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	LCS = (int**)malloc(sizeof(int*) * (len1 + 1));
	for (int i = 0;i <= len1;i++) {
		LCS[i] = (int*)malloc(sizeof(int) * (len2 + 1));
	}

	// init
	for (int i = 0;i <= len1;i++)
		LCS[i][0] = 0;

	for (int i = 0;i <= len2;i++)
		LCS[0][i] = 0;

	calLCS();

	int res = LCS[len1][len2];
	printf("%d", res);

	return 0;
}

void calLCS() {
	for (int i = 1;i <= strlen(s1);i++) {
		for (int j = 1;j <= strlen(s2);j++) {
			if (s1[i-1] == s2[j-1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = maximum(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}
}