#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int num[n];

	for (int i = 0; i < n; i++) {

		scanf("%d", &num[i]);
	}

	int count = 1;

	for (int i = 1; i < n; i++) {

		if (num[i] != num[i - 1]) {
			count++;
		}
	}

	printf("%d", count);
	return 0;
}