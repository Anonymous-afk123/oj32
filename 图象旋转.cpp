#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int img[n][m];
	int rot[m][n];

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			scanf("%d", &img[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			rot[i][j] = img[n - j - 1][i];
		}
	}

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			printf("%d", rot[i][j]);

			if (j < n - 1)
				printf(" ");
		}

		printf("\n");
	}

	return 0;
}