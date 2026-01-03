#include <stdio.h>
#include <string.h>

typedef struct {
	char id[21];
	int scores;
	int escore;
} Student;

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	Student stu[m];

	for (int i = 0; i < m; i++) {

		scanf("%s %d %d", stu[i].id, &stu[i].scores, &stu[i].escore);
	}

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < m - i - 1; j++) {

			int swap = 0;

			if (stu[j].scores < stu[j + 1].scores) {
				swap = 1;
			} else if (stu[j].scores == stu[j + 1].scores && stu[j].escore < stu[j + 1].escore) {
				swap = 1;
			} else if (stu[j].scores == stu[j + 1].scores && stu[j].escore == stu[j + 1].escore
			           && strcmp(stu[j].id, stu[j + 1].id) > 0) {
				swap = 1;
			}

			if (swap) {
				Student temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {

		printf("%s %d %d\n", stu[i].id, stu[i].scores, stu[i].escore);
	}

	return 0;
}