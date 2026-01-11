#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	int sum = 0;

	for (int i = 1; i <= n; i++) {

		int tempSum = 1;

		for (int j = 1; j <= i; j++) {

			tempSum *= j;
		}

		sum += tempSum;
	}

	printf("%d", sum);
	return 0;
}