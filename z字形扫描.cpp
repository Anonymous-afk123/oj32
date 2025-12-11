#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int mat[n][n];

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			scanf("%d", &mat[i][j]);
		}
	}

	for (int d = 0; d <= 2 * n - 2; d++) {

		int start = (d < n ? d : n - 1);  // ★ 防止 i 越界

		if (d % 2 == 0) {
			for (int i = start; i >= 0; i--) {

				int j = d - i;

				if (j >= 0 && j < n)       // ★ 防止 j 越界
					printf("%d ", mat[i][j]);
			}
		}

		else {
			for (int i = 0; i <= start; i++) {

				int j = d - i;

				if (j >= 0 && j < n)       // ★ 防止 j 越界
					printf("%d ", mat[i][j]);
			}
		}
	}

	return 0;
}