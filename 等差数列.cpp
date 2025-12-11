#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);

	if (n == 0) {
		printf("no\n");
		return 0;
	}

	int num[100];

	for (int i = 0; i < n; i++) {

		scanf("%d", &num[i]);
	}

	if (n == 1) {
		printf("0\n");
		return 0;
	}

	for (int i = 0; i < n - 1; i++)

		for (int j = 0; j < n - i - 1; j++) {

			if (num[j] < num[j + 1]) {
				int temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}

	for (int i = 1; i < n - 1; i++) {

		if (num[i + 1] - num[i] != num[i] - num[i - 1]) {
			printf("no\n");
			return 0;
		}
	}

	printf("%d\n", num[0] - num[1]);
	return 0;
}