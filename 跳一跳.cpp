# include<stdio.h>

int main() {
	int jump;
	int score = 0;
	int center = 0;

	while (scanf("%d", &jump) == 1 && jump != 0) {
		if (jump == 1) {
			score += 1;
			center = 0;
		}

		if (jump == 2) {
			center++;
			score += 2 * center;
		}
	}

	printf("%d", score);
	return 0;
}

