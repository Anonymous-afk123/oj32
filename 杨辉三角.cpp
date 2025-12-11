#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int triangle[10][10] = {0};

	for (int i = 0; i < n; i++) {

		triangle[i][0] = 1;
		triangle[i][i] = 1;

		for (int j = 1; j < i; j++) {

			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];

		}
	}

	for (int i = 0; i < n; i++) {

		for (int j = 0; j <= i; j++) {

			printf("%d", triangle[i][j]);

			if (j != i)
				printf(" "); // 元素间加空格
		}

		printf("\n"); // 每行换行
	}

	return 0;
}