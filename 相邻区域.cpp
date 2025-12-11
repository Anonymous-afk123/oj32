#include <stdio.h>

int main() {
	int n, m, t, k;
	scanf("%d %d %d %d", &n, &m, &t, &k);
	int mat[n][m];

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			scanf("%d", &mat[i][j]);
		}
	}

	int count[t + 1];

	for (int i = 0; i <= t; i++)

		count[i] = 0;
	int x;

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			if (mat[i][j] == k) {
				if (i - 1 >= 0) {
					x = mat[i - 1][j];
					count[x]++;
				}

				if (i + 1 < n) {
					x = mat[i + 1][j];
					count[x]++;
				}

				if (j - 1 >= 0) {
					x = mat[i][j - 1];
					count[x]++;
				}

				if (j + 1 < m) {
					x = mat[i][j + 1];
					count[x]++;
				}
			}
		}
	}

	int cnt = 0;

	for (int x = 1; x <= t; x++) {

		if (x != k && count[x] > 0)
			cnt++;
	}


	printf("%d\n", cnt);
	return 0;
}