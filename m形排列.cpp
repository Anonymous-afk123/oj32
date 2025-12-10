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

			if (input[j] > input[j + 1]) {
				int temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
			}
		}
	}

	int index = 0;

	for (int j = 0; j < n; j++) {

		if (j % 2 == 0) {
			for (int i = m - 1; i >= 0; i--) {

				output[i][j] = input[index++];
			}
		} else {
			for (int i = 0; i < m; i++) {

				output[i][j] = input[index++];
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