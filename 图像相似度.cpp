#include <stdio.h>
#include <stdlib.h>

int main() {
	int m, n;
	scanf("%d %d", &m, &n);

	int img1[m][n], img2[m][n];

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			scanf("%d", &img1[i][j]);
		}
	}

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			scanf("%d", &img2[i][j]);
		}
	}

	int cnt = 0;

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			if (img1[i][j] == img2[i][j])
				cnt++;
		}
	}

	int sum = m * n;
	double like_rate = (double)cnt * 100 / (double)sum;
	printf("%.2lf\n", like_rate);
	return 0;
}