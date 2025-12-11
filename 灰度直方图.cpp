#include <stdio.h>

int main() {
	int m, n;
	scanf("%d %d", &n, &m);
	int grey[m][n];

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			scanf("%d", &grey[i][j]);
		}
	}

	for (int k = 0; k < 16; k++) {

		int count = 0;

		for (int i = 0; i < m; i++) {

			for (int j = 0; j < n; j++) {

				if (grey[i][j] == k)
					count++;
			}
		}

		if (count)
			printf("%d %d\n", k, count);
	}

	return 0;
}