#include <stdio.h>

void isTriangle();
int main() {
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {


		isTriangle();
	}

	return 0;
}

void isTriangle() {
	int n;
	scanf("%d", &n);

	int matrix[n][n];

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			scanf("%d", &matrix[i][j]);
		}
	}

	int count = 0;

	for (int i = 1; i < n; i++) {

		for (int j = 0; j < i; j++) {

			if (matrix[i][j] != 0) {
				count = 1;
				break;
			}
		}
	}

	if (!count)
		puts("YES\n");
	else
		puts("NO\n");
}