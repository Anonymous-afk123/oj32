#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);

	int x[n][n];

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			scanf("%d", &x[i][j]);
		}

	}

	int y[n][n];

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			int sum = 0;

			for (int k = -1; k <= 1; k++) {

				for (int t = -1; t <= 1; t++) {

					if (i + k < 0 || i + k > n - 1 || j + t < 0 || j + t > n - 1)
						continue;
					else
						sum += x[i + k] [j + t];
				}

			}

			y[i][j] = (int)((float)sum / 9 + 0.5);
		}
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			printf("%d", y[i][j]);

			if (j != n - 1)
				printf(" ");
		}

		printf("\n");
	}

	return 0;
}