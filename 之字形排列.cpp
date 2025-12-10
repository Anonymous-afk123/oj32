#include <stdio.h>

void sort_array(int *input, int m, int n);

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int input[m][n];

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			scanf("%d", &input[i][j]);
		}
	}

	sort_array(&input[0][0], m, n);
	return 0;
}

void sort_array(int *input, int m, int n) {
	int output[m][n];
	int total = m * n;

	for (int i = 0; i < total - 1; i++) {

		for (int j = 0; j < total - i - 1; j++) {

			if (input[j] < input[j + 1]) {
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < m; i++) {

		// 偶数行从左到右，奇数行从右到左
		if (i % 2 == 0) {  // 偶数行
			for (int j = 0; j < n; j++) {

				int index = i * n + j;
				output[i][j] = input[index];
			}
		} else {  // 奇数行：从右到左
			for (int j = 0; j < n; j++) {

				int index = i * n + (n - 1 - j);  // 反向索引
				output[i][j] = input[index];
			}
		}
	}

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {

			printf("%d", output[i][j]);

			if (j != n - 1)
				printf(" ");
		}

		printf("\n");
	}
}