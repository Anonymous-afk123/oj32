#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[13];
	int wins;
	int score;
} Team;

int main() {
	int n;
	scanf("%d", &n);

	Team teams[10];

	for (int i = 0; i < n; i++) {

		scanf("%s", teams[i].name);
		teams[i].wins = 0;
		teams[i].score = 0;
	}

	int score[n][n];

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			scanf("%d", &score[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			switch (score[i][j]) {
				case 5:
					teams[i].wins++;
					teams[i].score += 2;
					break;

				case 4:
				case 3:
					teams[i].wins++;
					teams[i].score += 3;
					break;

				case -5:
					teams[i].score++;
					break;

				case -4:
				case -3:
					break;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - 1 - i; j++) {

			int swapNeeded = 0;

			// 1. 比較勝場
			if (teams[j].wins < teams[j + 1].wins) {
				swapNeeded = 1;
			} else if (teams[j].wins == teams[j + 1].wins) {
				// 2. 勝場相同，比較積分
				if (teams[j].score < teams[j + 1].score) {
					swapNeeded = 1;
				} else if (teams[j].score == teams[j + 1].score) {
					// 3. 積分也相同，比較名稱字典序 (小的在前)
					if (strcmp(teams[j].name, teams[j + 1].name) > 0) {
						swapNeeded = 1;
					}
				}
			}

			if (swapNeeded) {
				Team temp = teams[j];
				teams[j] = teams[j + 1];
				teams[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++) {

		printf("%s %d %d\n", teams[i].name, teams[i].wins, teams[i].score);
	}

	return 0;
}