#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	int count[n + 1] = {0};

	for (int i = 2; i <= n; i++) {

		int judge = 1;

		for (int j = 2; j < i; j++) {

			if (i % j == 0)
				judge = 0;
		}

		if (judge)
			count[i]++;
	}

	int found = 0;

	for (int i = 2; i <= n - 2; i++) {

		if (count[i] && count[i + 2]) {
			printf("%d %d\n", i, i + 2);
			found = 1;
		}
	}

	if (!found) {
		printf("empty\n");
	}

	return 0;
}