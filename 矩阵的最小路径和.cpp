#include <stdio.h>

int min (int a, int b) {
	return a < b ? a : b;
}

int main() {
	int matrix[500][500];
	int n = 0, m = 0;
	char ch;

	while (scanf("%c", &ch) && ch != '[');

	while (1) {
		m = 0;

		while (scanf("%c", &ch) && ch != '[');

		while (1) {
			scanf("%d", &matrix[n][m++]);
			scanf("%c", &ch);

			if (ch == ']')
				break;
		}

		n++;
		scanf("%c", &ch);

		if (ch == ']')
			break;
	}

	int dp[500][500];
	dp[0][0] = matrix[0][0];

	for (int i = 1; i < n; i++) {

		dp[i][0] = dp[i - 1][0] + matrix[i][0];
	}

	for (int j = 1; j < m; j++) {

		dp[0][j] = dp[0][j - 1] + matrix[0][j];
	}

	for (int i = 1; i < n; i++) {

		for (int j = 1; j < m; j++) {

			dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	printf("%d\n", dp[n - 1][m - 1]);

	return 0;
}