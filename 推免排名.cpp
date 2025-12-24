#include <stdio.h>

typedef struct {
	char id[6];
	char name[11];
	int scores[5];
	float credits[5];
	int extra_score;
	float final_score;
	int is_qualified;
} Student;

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	float R;
	scanf("%f", &R);

	Student stu[N];
	int qualified_count = 0;

	for (int i = 0; i < N; i++) {

		scanf("%s %s", stu[i].id, stu[i].name);

		float sum_weighted_score = 0;
		float sum_credits = 0;
		stu[i].is_qualified = 1;

		for (int j = 0; j < M; j++) {

			scanf("%d %f", &stu[i].scores[j], &stu[i].credits[j]);

			if (stu[i].scores[j] < 60) {
				stu[i].is_qualified = 0;
			}

			sum_weighted_score += stu[i].scores[j] * stu[i].credits[j];
			sum_credits += stu[i].credits[j];
		}

		scanf("%d", &stu[i].extra_score);

		stu[i].final_score = (sum_weighted_score / sum_credits) + stu[i].extra_score;
	}

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < N - i - 1; j++) {

			int need_swap = 0;

			if (stu[j].is_qualified < stu[j + 1].is_qualified) {
				need_swap = 1;
			} else if (stu[j].is_qualified == stu[j + 1].is_qualified &&
			           stu[j].final_score < stu[j + 1].final_score) {
				need_swap = 1;
			}

			if (need_swap) {
				Student temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < N; i++) {

		if (stu[i].is_qualified)
			qualified_count++;
	}

	int num = (int)(N * R + 0.5);

	if (num < 1)
		num = 1;

	int final_num = (num < qualified_count) ? num : qualified_count;

	for (int i = 0; i < final_num; i++) {

		printf("%s %s %.3f\n", stu[i].id, stu[i].name, stu[i].final_score);
	}

	return 0;
}
