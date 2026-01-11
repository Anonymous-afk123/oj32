#include <stdio.h>

int main() {
	char row[11][10];
	char col[11][10];
	int n = 0;

	while (scanf("%s", row[n])) {
		n++;

		if (getchar() == '\n')
			break;
	}

	for (int i = 0; i < n; i++) {

		scanf("%s", col[i]);
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			if (j >= i) {
				printf("%s", row[j - i]);
			} else {
				printf("%s", col[i - j]);
			}

			if (j < n - 1)
				printf(" ");
		}

		printf("\n");
	}

	return 0;
}