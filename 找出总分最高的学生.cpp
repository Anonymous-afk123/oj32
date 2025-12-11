#include <stdio.h>
#include <string.h>

typedef struct {
	int number;
	char name[50];
	int score1;
	int score2;
	int score3;
} Grade;

int main(void) {
	int n;
	scanf("%d", &n);
	Grade grade, best;
	int max = 0;
	int sum[n] = {0};

	for (int i = 0; i < n; i++) {


		scanf("%d %s %d %d %d", &grade.number, grade.name, &grade.score1, &grade.score2, &grade.score3);
		sum[i] = grade.score1 + grade.score2 + grade.score3;

		if (max < sum[i]) {
			max = sum[i];
			best = grade;
		}

	}

	printf("%s %d %d", best.name, best.number, max);
	return 0;
}
