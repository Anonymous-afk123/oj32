#include <stdio.h>
#include <string.h>

typedef struct {
	char name[50];
	int score;
} Grade;

int main(void) {
	int n;
	scanf("%d", &n);
	Grade grade;
	int level[3] = {0};

	for (int i = 1; i <= n; i++) {

		scanf("%s %d", grade.name, &grade.score)	;

		if (grade.score >= 0 && grade.score <= 59)
			level[0]++;

		else if (grade.score >= 60 && grade.score <= 79)
			level[1]++;

		else if (grade.score >= 80 && grade.score <= 100)
			level[2]++;
	}

	printf("%d %d %d", level[2], level[1], level[0]);
	return 0;
}