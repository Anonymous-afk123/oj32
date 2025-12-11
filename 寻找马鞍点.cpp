#include <stdio.h>

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int a[100][100];

	for (int i = 0; i < m; i++)

		for (int j = 0; j < n; j++)

			scanf("%d", &a[i][j]);

	for (int i = 0; i < m; i++) {

		int minCol = 0;

		for (int j = 1; j < n; j++)

			if (a[i][j] < a[i][minCol])
				minCol = j;

		int ok = 1;

		for (int k = 0; k < m; k++)

			if (a[k][minCol] > a[i][minCol]) {
				ok = 0;
				break;
			}

		if (ok) {
			printf("%d %d %d\n", i, minCol, a[i][minCol]);
			return 0; // ÕÒµ½¾Í½áÊø
		}
	}

	printf("no\n");
	return 0;
}