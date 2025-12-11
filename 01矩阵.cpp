#include <stdio.h>

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int numbers[m][n];

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			scanf("%d", &numbers[i][j]);
		}
	}


	for (int i = 0; i < m; i++) {

		int max = 0;
		int left = -1, right = -1;

		for (int j = 0; j < n;) {

			int start = j;
			int cnt = 0;

			while (j < n && numbers[i][j] == 1) {

				cnt++;
				j++;
			}

			if (cnt > max) {
				max = cnt;
				left = start;
				right = j - 1;
			}

			if (cnt == 0)
				j++;

		}

		if (max == 0) {
			printf("-1 -1\n");
		} else {
			printf("%d %d\n", left, right);
		}
	}

	return 0;
}