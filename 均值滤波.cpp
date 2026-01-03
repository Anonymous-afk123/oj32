#include <stdio.h>
#include <stdlib.h>

int main() {
	int x[16][16];

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) {

			scanf("%d", &x[i][j]);
		}

	}

	int y[16][16];

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) {

			if (i == 0 || i == 15 || j == 0 || j == 15) {
				y[i][j] = x[i][j];
			}

			else {
				int sum = 0;

				for (int k = -1; k <= 1; k++) {

					for (int t = -1; t <= 1; t++) {

						sum += x[i + k] [j + t];
					}
				}

				y[i][j] = sum / 9;
			}

		}
	}

	for (int i = 0; i < 16; i++) {

		for (int j = 0; j < 16; j++) {

			printf("%d", y[i][j]);

			if (j != 15)
				printf(" ");
		}

		printf("\n");
	}

	return 0;
}