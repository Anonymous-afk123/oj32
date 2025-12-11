#include <stdio.h>

int main() {
	int a1, a2, n;
	scanf("%d %d %d", &a1, &a2, &n);
	int num[10000];
	num[0] = a1;
	num[1] = a2;
	int length = 2;

	for (int i = 0; length < n; i++) {

		int product = num[i] * num[i + 1];

		if (product >= 10) {
			num[length++] = product / 10;

			if (length < n) {
				num[length++] = product % 10;
			}
		} else {
			num[length++] = product;
		}
	}

	for (int i = 0; i < n; i++) {

		printf("%d ", num[i]);
	}

	return 0;
}

